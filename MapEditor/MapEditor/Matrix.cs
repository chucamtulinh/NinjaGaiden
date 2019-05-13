using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapEditor
{
    class Matrix
    {
        private int column;
        private int row;
        private int[][] arr;

        public Matrix()
        {
            this.column = 0;
            this.row = 0;
            this.arr = null;
        }

        public Matrix(int r, int c, int value)
        {
            this.row = r;
            this.column = c;
            this.arr = new int[this.row][];
            for (int i = 0; i < row; i++)
            {
                this.arr[i] = new int[this.column];
            }
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    this.arr[i][j] = value;
                }
            }
        }

        public Matrix(int r, int c, int[][] array)
        {
            this.row = r;
            this.column = c;
            this.arr = new int[this.row][];
            for (int i = 0; i < row; i++)
            {
                this.arr[i] = new int[this.column];
            }
            for(int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    this.arr[i][j] = array[i][j];
                }
            }
        }

        public int[][] getArr()
        {
            return this.arr;
        }

        public int getRow()
        {
            return this.row;
        }

        public int getColumn()
        {
            return this.column;
        }

        public void setValue(int r, int c, int value)
        {
            this.arr[r][c] = value;
        }

        public int getValue(int r, int c)
        {
            return this.arr[r][c];
        }
    }
}
