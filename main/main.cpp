// main.cpp
#include <iostream>
#include "tinyxml2.h"
using namespace std;
using namespace tinyxml2;

void readXml()
{
    cout << "success" << endl;
    tinyxml2::XMLDocument doc("D:\\YM File\\OpenCode\\tinyxml2\\main\\menu.xml");   //文件路径要全，一开始我只写了文件名导致打不开文件纠结了好久
    if (!doc.LoadFile("D:\\YM File\\OpenCode\\tinyxml2\\main\\menu.xml"))
    {
        std::cout << "failed to load xml file!" << std::endl;
        // const char * error = doc;       //可以打印出错误信息

        // cout << error << endl;
    }

    tinyxml2::XMLHandle handler(&doc);      // handle的对象

    //结合xml文件看：
    //handler.FirstChild("breakfast_menu") 指的是获取breakfast_menu这个node的handler对象，返回值类型是TiXmlHandle
    //child("food,1")是指foods这个node下第2个food的node
    // TiXmlElement* desc = handler.FirstChild("breakfast_menu").FirstChild("foods").Child("food",1).FirstChildElement("description").ToElement();
    tinyxml2::XMLElement* desc = handler.FirstChild().ToElement();

    if (desc)
    {
        cout << "success" << endl;
    }
    else
    {
        cout << "error" << endl;
    }

    cout << desc->GetText() << endl;
}

int main()
{
    readXml();
}
