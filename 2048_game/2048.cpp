
 #include<iostream>
 #include<vector>
 #include<cstdlib>
 #include<string>
 #include<fstream>
 #include<cmath>

void rotate_anti_clock(std::vector<int>& v)
{
 std::vector<int> w;
 int side=std::sqrt(v.size());
 int k= side-1;
 while(k>-1)
 {
  for(int i=0; i<side; i++)
  {
   w.push_back(v[i*side+k]);
  }
  k--;
 }
 for(int i=0; i<v.size(); i++)
 {v[i]=w[i];}
}


void print_grid(const std::vector<int>& v)
{
 int side=std::sqrt(v.size());
 for(int i=0;i<side;i++)
 {
  for(int j=0;j<side;j++)
  {
   std::cout<<v[i*side+j]<<"\t";
  }
  std::cout<<std::endl;
 }
}

bool merge_num(std::vector<int>& v, int bi, int ei)
{
 std::vector<int> nonzero;
 std::vector<int> compare;
 int i,k;
 for(i=0;i<v.size();i++)
 {
  compare.push_back(v[i]);
 }
 for(i=bi;i<ei;i++)
 {
  if(v[i]!=0)
  {
   nonzero.push_back(v[i]);
  }
  v[i]=0;
 }
 nonzero.push_back(0);

 for(i=0;i<(nonzero.size()-1);i++)
 {
  k=i+1;
  if(nonzero[i]==nonzero[k])
  {
   v[bi]=2*nonzero[i];
   bi++;
   i++;
  }
  else
  {
   v[bi]=nonzero[i];
   bi++;
  }
 }
 int count=0;

 for(i=0;i<v.size();i++)
 {
  if(v[i]!=compare[i])
  {
   count++;
  }
 }
 if(count!=0)
 {
  return true;
 }
 else
 {
  return false;
 }
}

bool game_over(const std::vector<int>& v)
{
 int side= std::sqrt(v.size());
 for(int i=0; i<v.size(); i++)
 {
  if(v[i]==0)
  return false;
 }
 for(int i=0; i<side; i++)
 {
  for(int j=0; j<side-1; j++)
  {
   if(v[i*side+j]==v[i*side+j+1])
   {
    return false;
   }
  }
 }

 for(int i=0; i<side; i++)
 {
  for(int j=0; j<side-1; j++)
  {
   if(v[j*side+i]==v[j*side+i+side])
   {
    return false;
   }
  }
 }
 return true;
}


int main()
{
 std::vector<int> v;
 std::string filename;
 std::string ch;
 std::vector<int> a;
 int i, j, t, bi, ei, k, sum=0;

 std::cout << "please enter name of file containing the 2048 puzzle" << std::endl;
 std::cin >> filename;

 std::ifstream infile;
 infile.open(filename.c_str());

 if(!infile.is_open())
 {
  std::cout << "error, can't open input file" << std::endl;
  for(int z=0;z<15;z++)
  {
   v.push_back(0);
  }
  v.push_back(2);
 }

 int tmp;

 while(infile >> tmp)
 {
  v.push_back(tmp);
 }

 print_grid(v);

 int side = std::sqrt(v.size());

 while(!game_over(v))
 {
   std::cout<<"\n \n";
   std::string ch;
   std::cin>>ch;
   std::cout<<"\n \n";
   int sum=0;

   if(ch == "a"|| ch == "A")
   {
    for(int i=0;i<side;i++)
    {
     k=merge_num(v,i*side,i*side+side);
     sum=sum+k;
    }
   }
   else if(ch == "w" || ch == "W")
   {
    rotate_anti_clock(v);

    for(int i=0;i<side;i++)
    {
     k=merge_num(v,i*side,i*side+side);
     sum=sum+k;
    }

    rotate_anti_clock(v);
    rotate_anti_clock(v);
    rotate_anti_clock(v);
   }
   else if(ch == "d" || ch == "D")
   {
    rotate_anti_clock(v);
    rotate_anti_clock(v);

    for(int i=0;i<side;i++)
    {
     k=merge_num(v,i*side,i*side+side);
     sum=sum+k;
    }

    rotate_anti_clock(v);
    rotate_anti_clock(v);
   }
   else if(ch == "s" || ch == "S")
   {
    rotate_anti_clock(v);
    rotate_anti_clock(v);
    rotate_anti_clock(v);

    for(int i=0;i<side;i++)
    {
     k=merge_num(v,i*side,i*side+side);
     sum=sum+k;
    }

    rotate_anti_clock(v);
   }

   if(sum!=0)
   {
    std::vector<int> save_zero;
    int num=0;

    for(int i=0;i<v.size();i++)
    {
     if(v[i]==0)
     {
      save_zero.push_back(i);
      num++;
     }
    }
    int t=rand() % num;
    v[save_zero[t]]=2;
    print_grid(v);
   }
  }
  std::cout<<"GAME OVER"<<std::endl;
}
