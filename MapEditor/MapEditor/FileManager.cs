using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MapEditor
{
    class FileManager
    {
        public bool ReadFile(ref string resource, ref int width, ref int height, ref int row, ref int column, ref int[][] matrix)
        {
            BinaryReader br;
            try
            {
                br = new BinaryReader(new FileStream("D:\\D\\Map1.dat", FileMode.Open));
            }
            catch (IOException e)
            {
                //Console.WriteLine(e.Message + "\n Cannot open file.");
                return false;
            }
            try
            {
                resource = br.ReadString();
                width = br.ReadInt32();
                height = br.ReadInt32();
                row = br.ReadInt32();
                column = br.ReadInt32();
                matrix = new int[row][];
                for (int i = 0; i < row; i++)
                {
                    matrix[i] = new int[column];
                }
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        matrix[i][j] = br.ReadInt32();
                    }
                }
            }
            catch (IOException e)
            {
                //Console.WriteLine(e.Message + "\n Cannot read from file.");
                return false;
            }
            br.Close();
            return true;
        }

        public bool WriteFile(string resource, int width, int height, int row, int column, int[][] matrix)
        {
            //Ghi file nhi nhap cho c#
            BinaryWriter bw;
            FileStream outStream = File.Create("D:\\Courses\\SE102\\Map1.dat");
            try
            {
                bw = new BinaryWriter(outStream);
                bw.Flush();
            }
            catch (IOException e)
            {
                //Console.WriteLine(e.Message + "\n Cannot create file.");
                return false;
            }

            try
            {
                bw.Write(resource);
                bw.Write(width);
                bw.Write(height); 
                bw.Write(row);
                bw.Write(column);
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {     
                        bw.Write(matrix[i][j]); 
                    }
                }
            }
            catch (IOException e)
            { 
                bw.Close();
                //Console.WriteLine(e.Message + "\n Cannot write to file.");
                return false;
            }
            bw.Close();

            try
            {
                //Ghi file text cho c++
                StreamWriter writer = File.CreateText(@"D:\\Courses\\SE102\\Map1.txt");//tao 1 file ten la sieuthiit.doc trong o dia C
                writer.WriteLine(width);
                writer.WriteLine(height);
                writer.WriteLine(row);
                writer.WriteLine(column);
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        writer.Write(++matrix[i][j] + ",");
                    }
                    writer.WriteLine();
                }

                writer.Flush();//day file vao bo nho dem
                writer.Close();
            }
            catch (IOException e)
            {
                //Console.WriteLine(e.Message + "\n Cannot write to file.");
                return false;
            }
            return true;
        }
    }

}
