using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab2Form
{
    public partial class Form1 : Form
    {
        private Vector4[] cube;
        float size = 100f;
        Vector4 position = new Vector4(0, 0, 0, 0);
        float yaw = 0;
        float pitch = 0;
        float roll = 0;

        private TrackBar tbSize;
        private TrackBar tbRoll;
        private TrackBar tbPitch;

        public Form1()
        {
            InitializeComponent();

            SetStyle(ControlStyles.AllPaintingInWmPaint | ControlStyles.OptimizedDoubleBuffer | ControlStyles.UserPaint, true);

            ////tbSize = new TrackBar { Parent = this, Maximum = 1000, Left = 0, Value = 100 };
            tbRoll = new TrackBar { Parent = this, Maximum = 180, Left = 110, Value = 30 };
            tbPitch = new TrackBar { Parent = this, Maximum = 180, Left = 220, Value = 30 };

            ////tbSize.ValueChanged += tb_ValueChanged;
            tbRoll.ValueChanged += tb_ValueChanged;
            tbPitch.ValueChanged += tb_ValueChanged;

            tb_ValueChanged(null, EventArgs.Empty);
        }

        void tb_ValueChanged(object sender, EventArgs e)
        {
            size = Width < Height ? Width / 2 : Height /2;
            pitch = (float)(tbPitch.Value * Math.PI / 180);
            roll = (float)(tbRoll.Value * Math.PI / 180);

            cube = CreateCube(size, position, yaw, pitch, roll);

            Invalidate();
        }

        private Vector4[] CreateCube(float scale, Vector4 position, float yaw, float pitch, float roll)
        {
            //задаем вершины куба
            cube = new Vector4[5];
            cube[0] = new Vector4(1, 0, 0, 1);
            cube[1] = new Vector4(0, 1, 0, 1);
            cube[2] = new Vector4(-1, 0, 0, 1);
            cube[3] = new Vector4(0, -1, 0, 1);
            cube[4] = new Vector4(0, 0, 1, 1);
            //матрица масштабирования
            var scaleM = Matrix4x4.CreateScale(scale / 2);
            //матрица вращения
            var rotateM = Matrix4x4.CreateFromYawPitchRoll(yaw, pitch, roll);
            //матрица переноса
            var translateM = Matrix4x4.CreateTranslation(position);
            //результирующая матрица
            var m = translateM * rotateM * scaleM;
            //умножаем векторы на матрицу
            for (int i = 0; i < cube.Length; i++)
                cube[i] = m * cube[i];

            return cube;
        }

       

        protected override void OnPaint(PaintEventArgs e)
        {
            //создаем матрицу проекции на плоскость XY
            var paneXY = new Matrix4x4() { V00 = 1f, V11 = 1f, V33 = 1f };
            //рисуем
            DrawCube(e.Graphics, new Point(Width / 2, Height /2), paneXY);

            ////создаем матрицу проекции на плоскость XZ
            //var paneXZ = new Matrix4x4() { V00 = 1f, V12 = 1f, V33 = 1f };
            ////рисуем
            //DrawCube(e.Graphics, new Point(3*Width / 4, Height / 2), paneXZ);
        }

        void DrawCube(Graphics gr, PointF startPoint, Matrix4x4 projectionMatrix)
        {
            //проекция
            var p = new Vector4[cube.Length];
            for (int i = 0; i < cube.Length; i++)
                p[i] = projectionMatrix * cube[i];

            //создаем путь
            var path = new GraphicsPath();
            AddLine(path, p[0], p[1], p[2], p[3], p[0]);
            AddLine(path, p[0], p[4]);
            AddLine(path, p[1], p[4]);
            AddLine(path, p[2], p[4]);
            AddLine(path, p[3], p[4]);

            //AddLine(path, p[5], p[1]);
            //AddLine(path, p[2], p[6]);
            //AddLine(path, p[6], p[7]);
            //AddLine(path, p[7], p[3]);
            //сдвигаем
            gr.ResetTransform();
            gr.TranslateTransform(startPoint.X, startPoint.Y);
            //рисуем
            gr.DrawPath(Pens.Red, path);
        }

        void AddLine(GraphicsPath path, params Vector4[] points)
        {
            foreach (var p in points)
                path.AddLines(new PointF[] { new PointF(p.X, p.Y) });
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            size = Width < Height ? Width / 2 : Height / 2;

            pitch = (float)(tbPitch.Value * Math.PI / 180);
            roll = (float)(tbRoll.Value * Math.PI / 180);

            cube = CreateCube(size, position, yaw, pitch, roll);


            Invalidate();
        }

        bool mousePress = false;
        Point mousePressPoint;

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            mousePress = true;
            mousePressPoint = e.Location;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            mousePress = false;

        }

        float delta_roll = 30f;
        float delta_pitch = 30f;

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            //if (mousePress)
            //{
            //    float dx = e.X - mousePressPoint.X > 0 ? 0.05f : -0.05f;
            //    float dy = e.Y - mousePressPoint.Y > 0 ? 0.05f : -0.5f;



            //    delta_pitch += dy;
            //    delta_roll += dx;

            //    //if (delta_pitch > 180)
            //    //    delta_pitch = 180;

            //    //if (delta_roll > 180)
            //    //    delta_roll = 180;

            //    //if (delta_pitch < 0)
            //    //    delta_pitch = 0;

            //    //if (delta_roll < 0)
            //    //    delta_roll = 0;

            //    pitch = (float)(delta_pitch * Math.PI / 180);
            //    roll = (float)(delta_roll * Math.PI / 180);

            //    cube = CreateCube(size, position, yaw, pitch, roll);


            //    Invalidate();
            //}

        }
    }

    public struct Matrix4x4
    {
        public float V00;
        public float V01;
        public float V02;
        public float V03;
        public float V10;
        public float V11;
        public float V12;
        public float V13;
        public float V20;
        public float V21;
        public float V22;
        public float V23;
        public float V30;
        public float V31;
        public float V32;
        public float V33;

        public static Matrix4x4 Identity
        {
            get
            {
                Matrix4x4 m = new Matrix4x4();
                m.V00 = m.V11 = m.V22 = m.V33 = 1;
                return m;
            }
        }

        public static Matrix4x4 CreateScale(float scale)
        {
            var m = new Matrix4x4();
            m.V00 = m.V11 = m.V22 = scale;
            m.V33 = 1f;

            return m;
        }


        public static Matrix4x4 CreateRotationY(float radians)
        {
            Matrix4x4 m = Matrix4x4.Identity;

            float cos = (float)System.Math.Cos(radians);
            float sin = (float)System.Math.Sin(radians);

            m.V00 = m.V22 = cos;
            m.V02 = sin;
            m.V20 = -sin;

            return m;
        }

        public static Matrix4x4 CreateRotationX(float radians)
        {
            Matrix4x4 m = Matrix4x4.Identity;

            float cos = (float)System.Math.Cos(radians);
            float sin = (float)System.Math.Sin(radians);

            m.V11 = m.V22 = cos;
            m.V12 = -sin;
            m.V21 = sin;

            return m;
        }

        public static Matrix4x4 CreateRotationZ(float radians)
        {
            Matrix4x4 m = Matrix4x4.Identity;

            float cos = (float)System.Math.Cos(radians);
            float sin = (float)System.Math.Sin(radians);

            m.V00 = m.V11 = cos;
            m.V01 = -sin;
            m.V10 = sin;

            return m;
        }

        public static Matrix4x4 CreateFromYawPitchRoll(float yaw, float pitch, float roll)
        {
            return (CreateRotationY(yaw) * CreateRotationX(pitch)) * CreateRotationZ(roll);
        }

        public static Matrix4x4 CreateTranslation(Vector4 position)
        {
            Matrix4x4 m = Matrix4x4.Identity;

            m.V03 = position.X;
            m.V13 = position.Y;
            m.V23 = position.Z;

            return m;
        }

        public static Matrix4x4 operator *(Matrix4x4 matrix1, Matrix4x4 matrix2)
        {
            Matrix4x4 m = new Matrix4x4();

            m.V00 = matrix1.V00 * matrix2.V00 + matrix1.V01 * matrix2.V10 + matrix1.V02 * matrix2.V20 + matrix1.V03 * matrix2.V30;
            m.V01 = matrix1.V00 * matrix2.V01 + matrix1.V01 * matrix2.V11 + matrix1.V02 * matrix2.V21 + matrix1.V03 * matrix2.V31;
            m.V02 = matrix1.V00 * matrix2.V02 + matrix1.V01 * matrix2.V12 + matrix1.V02 * matrix2.V22 + matrix1.V03 * matrix2.V32;
            m.V03 = matrix1.V00 * matrix2.V03 + matrix1.V01 * matrix2.V13 + matrix1.V02 * matrix2.V23 + matrix1.V03 * matrix2.V33;

            m.V10 = matrix1.V10 * matrix2.V00 + matrix1.V11 * matrix2.V10 + matrix1.V12 * matrix2.V20 + matrix1.V13 * matrix2.V30;
            m.V11 = matrix1.V10 * matrix2.V01 + matrix1.V11 * matrix2.V11 + matrix1.V12 * matrix2.V21 + matrix1.V13 * matrix2.V31;
            m.V12 = matrix1.V10 * matrix2.V02 + matrix1.V11 * matrix2.V12 + matrix1.V12 * matrix2.V22 + matrix1.V13 * matrix2.V32;
            m.V13 = matrix1.V10 * matrix2.V03 + matrix1.V11 * matrix2.V13 + matrix1.V12 * matrix2.V23 + matrix1.V13 * matrix2.V33;

            m.V20 = matrix1.V20 * matrix2.V00 + matrix1.V21 * matrix2.V10 + matrix1.V22 * matrix2.V20 + matrix1.V23 * matrix2.V30;
            m.V21 = matrix1.V20 * matrix2.V01 + matrix1.V21 * matrix2.V11 + matrix1.V22 * matrix2.V21 + matrix1.V23 * matrix2.V31;
            m.V22 = matrix1.V20 * matrix2.V02 + matrix1.V21 * matrix2.V12 + matrix1.V22 * matrix2.V22 + matrix1.V23 * matrix2.V32;
            m.V23 = matrix1.V20 * matrix2.V03 + matrix1.V21 * matrix2.V13 + matrix1.V22 * matrix2.V23 + matrix1.V23 * matrix2.V33;

            m.V30 = matrix1.V30 * matrix2.V00 + matrix1.V31 * matrix2.V10 + matrix1.V32 * matrix2.V20 + matrix1.V33 * matrix2.V30;
            m.V31 = matrix1.V30 * matrix2.V01 + matrix1.V31 * matrix2.V11 + matrix1.V32 * matrix2.V21 + matrix1.V33 * matrix2.V31;
            m.V32 = matrix1.V30 * matrix2.V02 + matrix1.V31 * matrix2.V12 + matrix1.V32 * matrix2.V22 + matrix1.V33 * matrix2.V32;
            m.V33 = matrix1.V30 * matrix2.V03 + matrix1.V31 * matrix2.V13 + matrix1.V32 * matrix2.V23 + matrix1.V33 * matrix2.V33;

            return m;
        }

        public static Vector4 operator *(Matrix4x4 matrix, Vector4 vector)
        {
            return new Vector4(
                matrix.V00 * vector.X + matrix.V01 * vector.Y + matrix.V02 * vector.Z + matrix.V03 * vector.W,
                matrix.V10 * vector.X + matrix.V11 * vector.Y + matrix.V12 * vector.Z + matrix.V13 * vector.W,
                matrix.V20 * vector.X + matrix.V21 * vector.Y + matrix.V22 * vector.Z + matrix.V23 * vector.W,
                matrix.V30 * vector.X + matrix.V31 * vector.Y + matrix.V32 * vector.Z + matrix.V33 * vector.W
                );
        }
    }

    public struct Vector4
    {
        public float X;
        public float Y;
        public float Z;
        public float W;

        public Vector4(float x, float y, float z, float w)
        {
            X = x;
            Y = y;
            Z = z;
            W = w;
        }
    }
}
