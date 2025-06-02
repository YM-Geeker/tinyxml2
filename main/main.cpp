// main.cpp
#include <iostream>
#include "../tinyxml2.h"
#include "../tinyxml2.cpp" //need to have it -- why?
using namespace std;
using namespace tinyxml2;

void readXml()
{
    cout << "success" << endl;
    tinyxml2::XMLDocument doc;   //文件路径要全，一开始我只写了文件名导致打不开文件纠结了好久
    if (doc.LoadFile("D:/YM File/OpenCode/tinyxml2/main/menu.xml") != XMLError::XML_SUCCESS)
    {
        std::cout << "failed to load xml file!" << std::endl;
        // const char * error = doc;       //可以打印出错误信息

        std::cout << doc.ErrorIDToName(doc.ErrorID()) << std::endl;
    }
    std::cout << doc.ErrorIDToName(doc.ErrorID()) << std::endl;
    const XMLElement* Element = doc.FirstChildElement();
    const char* p = Element->GetText();
    if (p == nullptr)  {
        const char* s = "nullptr" ;
        std::cout << s << std::endl;
    }
    else  {
        std::cout << p << std::endl;
    }
    // tinyxml2::XMLHandle handler(&doc);      // handle的对象

    // //结合xml文件看：
    // //handler.FirstChild("breakfast_menu") 指的是获取breakfast_menu这个node的handler对象，返回值类型是TiXmlHandle
    // //child("food,1")是指foods这个node下第2个food的node
    // // TiXmlElement* desc = handler.FirstChild("breakfast_menu").FirstChild("foods").Child("food",1).FirstChildElement("description").ToElement();
    // tinyxml2::XMLElement* desc = handler.FirstChild().ToElement();

    // if (desc)
    // {
    //     cout << "success" << endl;
    // }
    // else
    // {
    //     cout << "error" << endl;
    // }

    // cout << desc->GetText() << endl;
}

//function：create a xml file
//param：xmlPath:xml文件路径
//return：0,成功；非0，失败
int createXML(const char* xmlPath) {
	const char* declaration ="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
	XMLDocument doc;
	doc.Parse(declaration);//会覆盖xml所有内容
	
	//添加申明可以使用如下两行
	//XMLDeclaration* declaration=doc.NewDeclaration();
	//doc.InsertFirstChild(declaration);

	XMLElement* root=doc.NewElement("DBUSER");
	doc.InsertEndChild(root);

	return doc.SaveFile(xmlPath);
}

void readXML(const char* xmlPath) {
    XMLDocument doc;
    doc.LoadFile(xmlPath);

    // 获取根节点 <book>
    XMLElement* book = doc.FirstChildElement("book");

    // 获取 <title> 节点
    XMLElement* title = book->FirstChildElement("title");
    const char* titleText = title->GetText();  // -> "XML入门"
    std::cout << titleText << std::endl;

    // 获取 <author> 节点
    XMLElement* author = title->NextSiblingElement("author");
    const char* authorText = author->GetText(); // -> "张三"
    std::cout << authorText << std::endl;

}

int main()
{
    readXML("D:\\YM File\\OpenCode\\tinyxml2\\main\\book.xml");
    createXML("D:\\YM File\\OpenCode\\tinyxml2\\main\\menu.xml");
}
