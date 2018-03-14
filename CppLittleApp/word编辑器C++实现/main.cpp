#include <iostream>
#include<vector>
#include<cstdlib>
#include<fstream>//1:输入\b,别换行就好，2菜单做函数，界面清除，选择后出菜单3：换行出界面即界面布局，界面优化，界面删:4：颜色变化
using namespace std;//多态虚函数未成功//双重case

class newone
{
public:
    vector<string>v;
    newone(vector<string> v1)
    {
        v=v1;
    }
    void  display()
    {
        int i=0;
        for(i=0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
    }
    void  add(string y)
    {
        v.push_back(y);
    }
    void  readd()
    {
        string save;
        while(cin>>save&&save!="end")
        {
            v.push_back(save);
        }
    }
    void  clean()
    {
        v.clear();
        cout<<"                      新建成功"<<endl;
    }

    void  save()
    {
        ofstream out;

        out.open("D:\\new.txt");
        int i=0;
        for(i=0; i<v.size(); i++)
        {
            out<<v[i];

        }
        cout<<"                          存储成功"<<endl;
        out.close();
    }
    void  read()
    {

        ifstream in;
        in.open("D:\\new.txt");
        int i=0;
        for(i=0; i<v.size(); i++)
        {
            in>>v[i];
            cout<<v[i]<<" ";

        }
        in.close();
    }//读取
    void  saveas(int k)
    {
        ofstream out;
        switch(k)
        {
        case 1:
            out.open("C:\\desktop");
            int i;
            for(i=0; i<v.size(); i++)
            {
                out<<v[i];

            }
            cout<<"                       存储成功"<<endl;
            out.close();
            break;

        case 2:
            out.open("D:\\new.txt");

            for(i=0; i<v.size(); i++)
            {
                out<<v[i];

            }
            cout<<"                            存储成功"<<endl;
            out.close();
            break;
        case 3:
            out.open("F:\\new.txt");

            for(i=0; i<v.size(); i++)
            {
                out<<v[i];

            }
            cout<<"                         存储成功"<<endl;
            out.close();
            break;
        case 4:
            out.open("C:\\new.txt");

            for(i=0; i<v.size(); i++)
            {
                out<<v[i];

            }
            cout<<"                              存储成功"<<endl;
            out.close();
            break;

        }

    }
    void  virtual delete1(string y,string z)
    {
        vector<string>::iterator it1;
        vector<string>::iterator it2;
        for(it1=v.begin(); it1!=v.end(); it1++)
        {
            if(*it1==y)
            {
                break;
            }
        }
        for(it2=v.begin(); it2!=v.end(); it2++)
        {
            if(*it2==z)
            {
                break;
            }
        }
        v.erase(it1,it2);

    }
    void virtual reset(string y,string z)
    {
        vector<string>::iterator it1;
        for(it1=v.begin(); it1!=v.end(); it1++)
        {
            if(*it1==y)
            {
                *it1=z;
            }

        }

    }

    void virtual insert(string y,string z)
    {
        vector<string>::iterator it1;
        for(it1=v.begin(); it1!=v.end(); it1++)
        {
            if(*it1==z)
            {
                it1=v.insert(it1,y);
            }

        }

    }




};



class anotherone:public newone
{
public:
    anotherone(vector<string> v1):newone(v1)
    {
        v=v1;
    }

    void delete1(string y,string z)
    {
        vector<string>::iterator it1;
        vector<string>::iterator it2;
        for(it1=v.begin(); it1!=v.end(); it1++)
        {
            if(*it1==y)
            {
                break;
            }
        }
        for(it2=v.begin(); it2!=v.end(); it2++)
        {
            if(*it2==z)
            {
                break;
            }
        }
        v.erase(it1,it2);

    }
    void reset(string y,string z)
    {
        vector<string>::iterator it1;
        for(it1=v.begin(); it1!=v.end(); it1++)
        {
            if(*it1==y)
            {
                *it1=z;
            }

        }

    }

    void insert(string y,string z)
    {
        vector<string>::iterator it1;
        for(it1=v.begin(); it1!=v.end(); it1++)
        {
            if(*it1==z)
            {
                it1=v.insert(it1,y);
            }

        }

    }
};
int temp;
void menu()
{

    system("color 24");
    cout<<endl<<endl<<endl<<endl;
    cout<<"                       *************************************\n";
    cout<<"                        *             0:exit            * \n";
    cout<<"                          *           1:new           *      \n";
    cout<<"                            *         2:write       *         \n";
    cout<<"                              *       3:save      *      \n";
    cout<<"                                *     4:save as *          \n";
    cout<<"                                  *   5:show  *             \n";
    cout<<"                                *     6:reset    *           \n";
    cout<<"                              *       7:delete     *          \n";
    cout<<"                            *         8:insert       *        \n";
    cout<<"                          *           9:add            *       \n";
    cout<<"                        *             10:read            *     \n";
    cout<<"                       *************************************\n";

    cout<<"                    请输入您要进行的操作< >\b\b";
    cin>>temp;

}

int main()
{

    vector<string>v1(1,"");
    vector<string>::iterator it1;
    vector<string>::iterator it2;
    vector<string>v2(1,"save");
    string save,de1,de2;
    int i=0;
    int temp1,temp2;
    class newone fir(v1);
    class anotherone six(v1);




    menu();
    for(i=1; i!=0; i++)
    {
        switch(temp)
        {
        case 0:
            return 0;
            menu();
            system("cls");
            break;
        case 1:
            six.clean();
            cout<<"                       返回菜单请按1"<<endl;
            cin>>temp2;
            if(temp2==1)
            {
                menu();
            }
            system("cls");
            break;
        case 2:
            system("color F0");
            cout<<"                请进行编辑,请以end结束"<<endl;
            while(cin>>save&&save!="end")
            {
                six.add(save);
            }
            cout<<"                       返回菜单请按1"<<endl;
            cin>>temp2;
            if(temp2==1)
            {
                menu();
            }
            system("cls");
            break;

        case 5:
            system("color F0");
            six.display();
            cout<<"                       返回菜单请按1"<<endl;
            cin>>temp2;
            if(temp2==1)
            {
                menu();
            }
            system("cls");
            break;
        case 9:
            six.readd();
            cout<<"                       返回菜单请按1"<<endl;
            cin>>temp2;
            if(temp2==1)
            {
                menu();
            }
            system("cls");
            break;
        case 10:
            system("color F0");
            six.read();
            cout<<"                       返回菜单请按1"<<endl;
            cin>>temp2;
            if(temp2==1)
            {
                menu();
            }
            system("cls");
            break;
        case 4:

            cout<<"                   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
            cout<<"                              1:C:\\desktop                 \n";
            cout<<"                              2:D;\\new.txt                \n";
            cout<<"                              3:F:\\new.txt                \n";
            cout<<"                              4:C:\\new.txt                \n";
            cout<<"                   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
            cout<<"\t\t\t请选择您要存储的地址< >\b";
            cin>>temp1;
            switch(temp1)
            {
            case 1:
                six.saveas(1);
                cout<<"                       返回菜单请按1"<<endl;
                cin>>temp2;
                if(temp2==1)
                {
                    menu();
                }
                system("cls");
                break;
            case 2:
                six.saveas(2);
                cout<<"                       返回菜单请按1"<<endl;
                cin>>temp2;
                if(temp2==1)
                {
                    menu();
                }
                system("cls");
            case 3:
                six.saveas(3);
                cout<<"                       返回菜单请按1"<<endl;
                cin>>temp2;
                if(temp2==1)
                {
                    menu();
                }
                system("cls");
            case 4:
                six.saveas(4);
                cout<<"                       返回菜单请按1"<<endl;
                cin>>temp2;
                if(temp2==1)
                {
                    menu();
                }
                system("cls");
            }
            break;
        case 3:
            six.save();
            cout<<"                       返回菜单请按1"<<endl;
            cin>>temp2;
            if(temp2==1)
            {
                menu();
            }
            system("cls");
            break;
        case 7:
            cout<<"                         请输入要删除的第一个单词"<<endl;
            cin>>de1;
            cout<<"                         请输入要删除的最后一个单词"<<endl;
            cin>>de2;
            six.delete1(de1,de2);
            cout<<"                       返回菜单请按1"<<endl;
            cin>>temp2;
            if(temp2==1)
            {
                menu();
            }
            system("cls");
            break;
        case 6:
            cout<<"                     请输入要修改的单词"<<endl;
            cin>>de1;
            cout<<"                     请输入修改后的单词"<<endl;
            six.reset(de1,de2);
            cout<<"                       返回菜单请按1"<<endl;
            cin>>temp2;
            if(temp2==1)
            {
                menu();
            }
            system("cls");
            break;
        case 8:
            cout<<"                           请输入要插入的单词"<<endl;
            cin>>de1;
            cout<<"                           请输入要插入的单词的后一个单词"<<endl;
            cin>>de2;
            six.insert(de1,de2);
            cout<<"                       返回菜单请按1"<<endl;
            cin>>temp2;
            if(temp2==1)
            {
                menu();
            }
            system("cls");
            break;

        }

    }
}


