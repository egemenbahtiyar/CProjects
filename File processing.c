#include <stdio.h>
#include <stdlib.h>

struct Point3d {
    float x;
    float y;
    float z;
};

struct Point3d CenterMass(struct Point3d *arr){
    float arrSize=3644;
    float sumX=0;
    float sumY=0;
    float sumZ=0;
    for (int i = 0; i <arrSize ; ++i) {
        sumX+=arr[i].x;
        sumY+=arr[i].y;
        sumZ+=arr[i].z;
    }
    struct Point3d _point3D;
    _point3D.x=sumX/arrSize;
    _point3D.y=sumY/arrSize;
    _point3D.z=sumZ/arrSize;
    return _point3D;
}
void Translation(struct Point3d *arr){
    printf("Enter the translation vector x y z coordinates respectively:\n");
    struct Point3d TransVector;
    scanf("%f %f %f", &TransVector.x, &TransVector.y, &TransVector.z);
    float arrSize=3644;
    for (int i = 0; i <arrSize ; ++i) {
        arr[i].x=TransVector.x;
        arr[i].y=TransVector.y;
        arr[i].z=TransVector.z;
    }
}
void store(struct Point3d *arrV,struct Point3d *arrF) {

    FILE *MyTeaPot;

    MyTeaPot = fopen("/Users/Egemen/Desktop/MyTeaPot2.obj", "w");       // Careful about file location

    for (int i = 0; i < 3644; ++i) {
        fprintf(MyTeaPot,"v %.5f %.5f %.5f\n",arrV[i].x,arrV[i].y,arrV[i].z);
    }
    fprintf(MyTeaPot,"\n");
    for (int i = 0; i < 6320; ++i) {
        fprintf(MyTeaPot,"f %.0f %.0f %.0f\n",arrF[i].x,arrF[i].y,arrF[i].z);
    }
    printf("File has been created successfully.");

    fclose(MyTeaPot);
}

int main() {
    printf("Program name: MyRepo7\n");
    printf("By Egemen Bahtiyar 182010010070\n");
    printf("This program reads an obj file ,computes the center of mass of the model.\n");
    printf("And translates the model in given x,y,z direction.\n");
    printf("To run the program, you need to write a coordinates of translation vectors as x,y,z.\n");
    printf("Pay attention to the location of the file while performing these steps.\n\n");

    FILE* fp = fopen("/Users/Egemen/Desktop/teapot1.obj", "r");      // Careful about file location
    if (fp == NULL){
        printf("Cannot open the file for reading!");
        exit(1);
    }
    struct Point3d Point3D[3644];
    struct Point3d FPoints[6320];
    int i=0;
    int j=0;
    while (!feof(fp)) {
        struct Point3d tempPoint3D;
        char value;
        fscanf(fp, "%c %f %f %f\n", &value, &tempPoint3D.x, &tempPoint3D.y, &tempPoint3D.z);
        if(value == 'v'){
            Point3D[i]=tempPoint3D;
            i++;
        }
        if (value== 'f'){
            FPoints[j]=tempPoint3D;
            j++;
        }
        else{
            continue;
        }
    }

    struct Point3d Center=CenterMass(Point3D);
    printf("Center of mass is x: %f y: %f z: %f\n",Center.x,Center.y,Center.z);
    Translation(Point3D);
    store(Point3D,FPoints);

    fclose(fp);

    return 0;
}
