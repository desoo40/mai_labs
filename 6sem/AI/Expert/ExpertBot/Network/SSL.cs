using System.Net.Security;
using System.Security.Cryptography.X509Certificates;

namespace ExpertBot.Network
{
    public class SSL
    {
        public static bool Validator(object sender, X509Certificate certificate, X509Chain chain,
                              SslPolicyErrors sslPolicyErrors)
        {
            return true;
        }
    }
}
