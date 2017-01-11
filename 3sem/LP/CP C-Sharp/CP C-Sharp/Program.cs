using System;
using System.IO;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace CP_C_Sharp
{
    class Program
    {
        public static StreamReader Reader = File.OpenText("Sorokin Family.ged");

        static void Main(string[] args)
        { 
            var dictOfMembers = new Dictionary<string, string>();
            dictOfMembers["He"] = "Неизвестен";
            dictOfMembers["She"] = "Неизвестена";

            List<string> predicats = new List<string>();

            string tmp = "";
            string id = "";
            string name = "";

            while ((tmp = Reader.ReadLine()) != null)
            {
                if (tmp.StartsWith("0 @I"))
                    id = tmp.Substring(3, 7);

                if (tmp.StartsWith("1 NAME"))
                {
                    name = tmp.Substring(7);
                    name = name.Replace("/", "");

                    if (name == " ")
                        name = "Неизвестно";

                    dictOfMembers[id] = name;
                    id = "";
                }

                if (tmp.StartsWith("0 @F"))
                    predicats = PredicatsWriter(dictOfMembers, predicats);
            }
            

            File.WriteAllLines("cp_sorokin.pl", predicats);
            File.AppendAllText("cp_sorokin.pl", @"
bro_or_sist(X, Y) :-
    parents(X, F, M),
    parents(Y, F, M),
    X\=Y.

double(X, Y) :-
    parents(X, F1, M1),
    parents(Y, F2, M2),
    X\=Y,
    
    (bro_or_sist(F1, F2);
    bro_or_sist(F1, M2);
    bro_or_sist(M1, F2);
    bro_or_sist(M1, M2)).
    
triple(X, Y) :-
    parents(X, F1, M1),
    parents(Y, F2, M2),
    X\=Y,
    
   (double(F1, F2);
    double(F1, M2);
    double(M1, F2);
    double(M1, M2)).

relative(child, Child, Parent) :-
    parents(Child, _, Parent);
    parents(Child, Parent, _).

relative(husband, Husband, Wife) :-
    parents(_, Husband, Wife).

relative(wife, Wife, Husband) :-
    parents(_, Husband, Wife).

relative(father, Father, Child) :-
    parents(Child, Father, _).

relative(mother, Mother, Child) :-
    parents(Child, _, Mother).

relative(Way, A, B) :- 
    dpath(A, B, _, Way), !. 

print_ans([X]):- write(X),!.
print_ans([A,B|Tail]):- print_ans([B|Tail]), write(' - '), write(A).
print_ans(X):- write(X),!.

prolong([X|T],[Y,X|T], Rel) :-
    relative(Rel, X, Y),
    not(member(Y,[X|T])). 

dseach([X|T],X,[X|T], _). 
dseach(P,Y,L, [Rel|Tail]) :- 
    prolong(P,P1, Rel),
    dseach(P1,Y,L, Tail), !. 

dpath(X,Y,P, Way) :- 
    dseach([X],Y,L, Way),
    reverse(L,P), !.");
        }

        private static List<string> PredicatsWriter(Dictionary<string, string> dict, List<string> predicats)
        {
            string tmp = " ";
            string husband = "He";
            string wife = "She";
            
            List<string> children = new List<string>(); 

            while (!tmp.StartsWith("1 RIN"))
            {
                tmp = Reader.ReadLine();

                if (tmp == null)
                {
                    Console.WriteLine("Incorrect .ged file");
                    return predicats;
                }

                if (tmp.StartsWith("1 HUSB"))
                    husband = tmp.Substring(8, 7);

                if (tmp.StartsWith("1 WIFE"))
                    wife = tmp.Substring(8, 7);

                if (tmp.StartsWith("1 CHIL"))
                    children.Add(tmp.Substring(8, 7));
            }


            //foreach (var child in children)
            //{
            //    string pred = string.Format("parents(\"{0}\", \"{1}\", \"{2}\").", dict[child], dict[husband].TrimStart(), dict[wife].TrimEnd());
            //    predicats.Add(pred);
            //}

            // спасибо visual studio за упрощение кода

            predicats.AddRange(children.Select(child =>
                $"parents(\"{dict[child]}\", \"{dict[husband].TrimStart()}\", \"{dict[wife].TrimEnd()}\")."));

            return predicats;
        }

    }
}
