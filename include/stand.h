class cVertex
{
public:
    float coordinates [3];
};

class PolygonC
{
public:
    void addVertex(float x, float y, float z)
    {
        dummy.coordinates[0] = x;
        dummy.coordinates[1] = y;
        dummy.coordinates[2] = z;
        Vertices.push_back(dummy);
    }

    void drawPolygon(void)
    {
        glBegin(GL_POLYGON);
        glColor3f(Pcolour[0], Pcolour[1], Pcolour[2]);
        for(int i=0; i < Vertices.size(); i++){
            glVertex3f( Vertices.at(i).coordinates[0], Vertices.at(i).coordinates[1], Vertices.at(i).coordinates[2]);
        }
        glEnd();
    }

    void changePColour(float x, float y, float z)
    {
        Pcolour[0] = x;
        Pcolour[1] = y;
        Pcolour[2] = z;
    }

private:
    float Pcolour[3];
    cVertex dummy;
    std::vector<cVertex> Vertices;
};

float standardPColour[3] = {1.0, 1.0, 1.0};

Vertex dummy = Vertex(glm::vec3(0,0,0));

class Stand
{
public:
    void addPolygon(int n, std::vector<float> x, std::vector<float> y, std::vector<float> z, float Pcolour[3] = standardPColour){
        Vertex cVertices[ x.size() ];
        for(int i = 0; i < x.size(); i++)
        {
            cVertices[i] = Vertex( glm::vec3(x.at(i), y.at(i), z.at(i)) );
        }
        Mesh cMesh(cVertices, sizeof(cVertices)/sizeof(cVertices[0]));
        Collection.push_back(cMesh);
    }
    void drawStand(void){
        for(int i=0; i < Collection.size(); i++){
            Collection.at(i).Draw();
        }
    }
    Stand();
private:
    std::vector<Mesh> Collection;
};

std::vector<Stand *> stands;

Stand::Stand(){
    stands.push_back(this);
}
