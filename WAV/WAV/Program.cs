using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WAV
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream file = new FileStream(@"./../../Nekodex - Welcome to osu!.wav", FileMode.Open, FileAccess.Read);
            BinaryReader b = new BinaryReader(file);
            b.BaseStream.Seek(0, SeekOrigin.Begin);
            Byte b1;
            int i = 0;
            while (b.PeekChar() > -1)
            {
                b1 = b.ReadByte();
                i++;
                if (i >= 22 && i <= 23) 
                    Console.Write(b1);
                if (i == 24)
                    Console.WriteLine();
                if (i >= 24 && i <= 27)
                    Console.Write(b1);
                if (i == 27)
                    Console.WriteLine();
                if (i >= 34 && i <= 35)
                    Console.Write(b1);
                if (i == 35)
                    Console.WriteLine();
                if (i >= 40 && i <= 43)
                    Console.Write(b1);
                if (i == 43)
                {
                    Console.WriteLine();
                    break;
                }      
            }
            b.Close();
            file.Close();

        }
    }
}
