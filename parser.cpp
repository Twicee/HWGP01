// parser.cpp by Paul Jo

#include "parser.h"
#include <QColor>

gp::vector<Shape*> ParseFile(int size){
    ifstream in("shapes.txt"); // change location for needs

    if(!in){
        cout << "File didn't open.";
        exit(1);
    }

    gp::vector<Shape*> rShapes(size);
//    in.ignore('\n');

    while (in){
        string temp;
        int id;
        
        in.ignore('\n');

        in.ignore(numeric_limits<streamsize>::max(), ':');
        in >> id;
        in.ignore(numeric_limits<streamsize>::max(), ':');
        in >> temp;

        if (in.eof())
            break;
        
        switch(id){
        case 1:
            rShapes.push_back(readLine(in, id));
            break;
        case 2:
            rShapes.push_back(readPolyLine(in, id));
            break;
        case 3:
            rShapes.push_back(readPolygon(in, id));
            break;
        case 4:
            rShapes.push_back(readRectangle(in, id));
            break;
        case 5:
            rShapes.push_back(readSquare(in, id));
            break;
        case 6:
            rShapes.push_back(readEllipse(in, id));
            break;
        case 7:
            rShapes.push_back(readCircle(in, id));
            break;
        case 8:
            rShapes.push_back(ReadText(in, id));
            break;
        default:
            cout << "Error parser.cpp" << endl;
            break;
        }
    }

    in.close();
    return rShapes;
}

// All of the functions below are skeleton works.

Shape* readLine(ifstream &in, int id)
{
    // More works needed
    Line *line = new Line(qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, front, end);
    return line;
}

Shape* readPolyLine(ifstream &in, int id)
{
    Polyline *polyline = new Polyline(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, points);
    return polyline;
}

Shape* readPolygon(ifstream &in, int id)
{
    Polygon *polygon = new Polygon(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, points);
    return polygon;
}


Shape* readRectangle(ifstream& in, int id)
{
    Rectangle *rectangle = new Rectangle(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, l, w, x , y);
    return rectangle;
}

Shape* readSquare(ifstream& inFile, int id)
{
    Square *square = new Square(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, w, x , y);
    return square;
}

Shape* readEllipse(ifstream& in, int id)
{
    Ellipse *ellipse = new Ellipse(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, a, b, x, y ); // need qtBrushColor as well!!!!
    return ellipse;
}

Shape* readCircle(ifstream& in, int id)
{
    Circle *circle = new Circle(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, r, x, y); // maybe change the little plus thingss x+ r y+ r??
    return circle;
}


Shape* readText(ifstream& in, int id)
{
    Text *text = new Text(black, qtColor, SolidLine, FlatCap, MiterJoin, SolidPattern, fontPoint, id, align, fontFamily, fontStyle, fontWeight, textLine, x, y, length, width);
    return text;
}

// QColor getColor(string color)
// {

// }

// PenStyle getPenStyle(string style)
// {
    
// }

// PenCapStyle getPCStyle(string cap)
// {

// }

// PenJoinStyle getPJStyle(string join)
// {

// }

// BrushStyle getBrushStyle(string brush)
// {
    
// }
