class Camera{
public:
    float *calcPosRot(float cpos[3]){
        float result[3];
        result[0] = cpos[0]-pos[0];//)*cos((1-rot[0])*2*PI);
        result[1] = cpos[1]-pos[1];//)*sin((1-rot[1])*2*PI);
        result[2] = cpos[2]-pos[2];//)*cos((1-rot[2])*2*PI);
    };
private:
    float pos[3] = {0, 0, 0};
    float rot[3] = {0, 0, 0};
} camera1;
