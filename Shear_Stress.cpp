#include <iostream>
#include<cmath>
using namespace std;

int width, depth, y;
int shapeOfBeam, rectangle,circle,stressSelected;
double SF,BendingStress,MoI,As,yBar;
bool beam, center, typeofload, all;
int BMGiven, IGiven, sigmaGiven, yGiven, loadGiven, spanGiven ,SFGiven, AsGiven, bGiven,ybarGiven;
double bendingMoment, shearStress;

void qavg(double sf, double sa){
    shearStress = sf / sa;
    cout << "Average Shear Stress is " << shearStress << " N/mm^2" << endl;
    cout << "Maximum Shear Stress is " << (4.0/3.0) * shearStress << " N/mm^2" << endl;
}


int main() {
    cout<<"What you want to calculate?"<<endl;
    cout<<"1. Shear Stress"<<endl;
    cout<<"2. Bending Stress"<<endl;
    cout<<"Enter 1 or 2: ";
    cin>>stressSelected;
    if (stressSelected==2){
        cout << "What is given?" << endl;
        cout << "1. Bending Moment?" << endl;
        cout << "Enter 1:Yes or 0:No : "<<endl;
        cin >> BMGiven;
        if (BMGiven==1){
            cout<<"Enter Bending Moment (M) in kNm: ";
            cin>>bendingMoment;
        } else {
            cout<<"Enter given data to calculate Bending Moment."<<endl;
            cout<< "Enter type of beam enter 1 for simply supported, 0 for cantilever: ";
            cin>>beam;
            double load, length;
            double a, b;

            if (beam) {  // Simply supported beam
                cout << "Type of load enter 1 for point load, 0 for UDL: ";
                cin >> typeofload;

                if (typeofload) {  // Point Load
                    cout << "Enter load (W) in kN: ";
                    cin >> load;
                    cout << "Enter Span of Beam (L) in m: ";
                    cin >> length;
                    spanGiven=length;
                    cout << "Is the load at center? Enter 1 for yes, 0 for no: ";
                    cin >> center;

                    if (center) {
                        bendingMoment = (load * spanGiven) / 4;  // Max bending moment at center
                    }
                    else {
                        cout << "Enter distance 'a' from left support to load in m: ";
                        cin >> a;
                        b = length - a;
                        bendingMoment = (load * a * b) / length;  // Bending moment at distance 'a'
                    }
                }
                else {  // UDL
                    cout << "Enter load (W) in kN/m: ";
                    cin >> load;
                    cout << "Is the load covering entire span? Enter 1 for yes, 0 for no: ";
                    cin >> all;

                    if (all) {
                        length=spanGiven;
                        bendingMoment = (load * spanGiven * spanGiven) / 8;  // Max bending moment at center for full UDL
                    }
                    else {
                        cout << "Enter distance 'a' from left support to start of load in m: ";
                        cin >> a;
                        cout << "Enter distance 'b' from right support to end of load in m: ";
                        cin >> b;
                        // Shear at left support for partial UDL: Load * (length - b) * (length - b)/length
                        double loadLength = length - a - b;
                        bendingMoment = (load * loadLength * (length - b) * (length - b)) / (2 * length);
                    }
                }
            }
            else {  // Cantilever beam
                cout << "Enter Span of Beam (L) in m: ";
                cin >> length;
                cout << "Type of load enter 1 for point load, 0 for UDL: ";
                cin >> typeofload;

                if (typeofload) {  // Point Load
                    cout << "Enter load (W) in kN: ";
                    cin >> load;

                    cout << "Is the load at free end? Enter 1 for yes, 0 for no: ";
                    cin >> center;

                    if (center) {
                        a = length ;
                    }
                    else {
                        cout << "Enter distance 'a' from fixed support to load in m: ";
                        cin >> a;
                    }
                    bendingMoment = load * a;  // Max bending moment at fixed end for cantilever
                }
                else {  // UDL
                    cout << "Enter load (W) in kN/m: ";
                    cin >> load;

                    cout << "Is the load covering entire span? Enter 1 for yes, 0 for no: ";
                    cin >> all;

                    if (all) {
                        bendingMoment = (load * length * length) / 2;  // Max bending moment at fixed end for full UDL
                    }
                    else {
                        cout << "Enter distance 'a' from fixed support to start of load in m: ";
                        cin >> a;
                        cout << "Enter distance 'b' from free end to end of load in m: ";
                        cin >> b;
                        double loadLength = length - a - b;
                        bendingMoment = load * loadLength * (length - b) / 2;
                    }
                }
            }
        }

        cout << "2. Moment of Inertia (I)? :"<<endl ;
        cout << "Enter 1:Yes or 0:No : "<<endl ;
        cin >> IGiven;
        if (IGiven==1){
            cout<<"Enter Moment of Inertia (I) in mm^4: ";
            cin>>MoI;
        }
        else if (IGiven==0){
            cout << "Select shape of cross-section"<<endl;
            cout << "1. Rectangle" << endl;
            cout << "2. Circle" << endl;
            cout << "Enter 1 or 2: ";
            cin >> shapeOfBeam;

            if (shapeOfBeam == 1){
                cout << "You have selected Rectangle" << endl;
                cout << "---------------------------------" << endl;
                cout << "Enter width of rectangle: ";
                cin >> width;
                cout << "Enter depth of rectangle: ";
                cin >> depth;
                MoI = (width * pow(depth,3)) / 12.0;}

            else if (shapeOfBeam == 2){
                cout << "You have selected Circle" << endl;
                cout << "---------------------------------" << endl;
                cout << "Enter diameter of circle: ";
                cin >> depth;
                MoI = (M_PI * pow(depth,4)) / 64.0;
            }
      } 
        
      
        cout << "3. Distance from neutral axis to point where bending stress is to be calculated (y)? :";
        cout << "Enter 1:Yes or 0:For Ymax : ";
        cin >> yGiven;
        if (yGiven==1){
            cin >> yGiven;
        } else {
            yGiven=depth/2;
            cout<< "y is taken as "<<yGiven<<endl;
        }
      
        cout << "4. Bending Stress (σ)? :";
        cout << "Enter 1:Yes or 0:No : ";
        cin >> sigmaGiven;
        if (sigmaGiven==1){
            cin >> BendingStress;
            cout<< "Bending Stress is given as "<<BendingStress<<endl;
        } else {
            cout << "---------------------------------" << endl;
            cout<< "Calculating Bending Stress..."<<endl;
            cout << "Given Bending Moment (M) is "<<(bendingMoment*1000000)<<" Nmm"<<endl;
            cout << "Given Moment of Inertia (I) is "<<MoI<<" mm^4"<<endl;
            cout << "Given distance y is "<<yGiven<<" mm"<<endl;
            BendingStress = ((bendingMoment*1000000 )* yGiven) / MoI;
            cout<< "Calculated Bending Stress is "<<BendingStress<<" N/mm^2"<<endl;
        }
    
    } else if (stressSelected==1){
        cout << "---------------------------------" << endl;


        cout << "Shear stress Calculator"<<endl;
        cout << "Enter the Given Data: "<<endl;
        cout << "1. Shear Force " <<endl;
        cout << "Enter 1:Yes or 0:No : "<<endl;
        cin >> SFGiven;
        if (SFGiven == 1) {
            cout << "Enter the value in KN: " << endl;
            cin >>SF;
        } else if (SFGiven == 0) {
            cout << "Enter the given Data to find Shear Force "<<endl;
            cout << "Enter the type of beam :"<<endl;
            cout<< "Enter 1 for simply supported, 0 for cantilever: ";
            cin >> beam;

            double load, length;
            double a, b;

            cout << "Enter type of Load"<<endl;
            cout<< "Enter 1 for point load, 0 for UDL: ";
            cin >> typeofload;

            if (beam) {  // Simply supported beam
                cout << "Enter Span of Beam (L) in m: ";
                cin >> length;

                if (typeofload) {  // Point Load
                    cout << "Enter load (W) in kN: ";
                    cin >> load;

                    cout << "Is the load at center? Enter 1 for yes, 0 for no: ";
                    cin >> center;

                    if (center) {
                        SF = load / 2.0;  // Shear force at supports
                    }
                    else {
                        cout << "Enter distance 'a' from left support to load in m: ";
                        cin >> a;
                        b = length - a;
                        SF = (load * b) / length;  // Shear force at left support
                    }
                }
                else {  // UDL
                    cout << "Enter load (W) in kN/m: ";
                    cin >> load;
                    cout << "Is the load covering entire span? Enter 1 for yes, 0 for no: ";
                    cin >> all;

                    if (all) {
                        SF = (load * length) / 2.0;  // Shear force at supports for full UDL
                    }
                    else {
                        cout << "Enter distance 'a' from left support to start of load in m: ";
                        cin >> a;
                        cout << "Enter distance 'b' from right support to end of load in m: ";
                        cin >> b;
                        // Shear at left support for partial UDL: Load * (length - b) * (length - b)/length
                        double loadLength = length - a - b;
                        SF = load * loadLength * (length - b) / length;
                    }
                }
            }
            else {  // Cantilever beam
                cout << "Enter Span of Beam (L) in m: ";
                cin >> length;

                if (typeofload) {  // Point Load
                    cout << "Enter load (W) in kN: ";
                    cin >> load;

                    cout << "Is the load at free end?"<<endl;
                    cout << "1: Yes , 0: No: "<<endl;
                    cin >> center;

                    if (center) {
                        a = length ;
                    }
                    else {
                        cout << "Enter distance 'a' from fixed support to load in m: ";
                        cin >> a;
                    }
                    SF = load;  // Shear force at the fixed end equals the load for cantilever
                }
                else {  // UDL
                    cout << "Enter load (W) in kN/m: ";
                    cin >> load;

                    cout << "Is the load covering entire span? Enter 1 for yes, 0 for no: ";
                    cin >> all;

                    if (all) {
                        SF = load * length;
                    }
                    else {
                        cout << "Enter distance 'a' from fixed support to start of load in m: ";
                        cin >> a;
                        cout << "Enter distance 'b' from free end to end of load in m: ";
                        cin >> b;
                        double loadLength = length - a - b;
                        SF = load * loadLength;
                    }
                }
            }
    
            cout << "Calculated Shear Force: " << SF << " kN" << endl;
        }
        
        
        cout << "---------------------------------" << endl;


        cout << "2. Moment of Inertia (I)? :"<<endl ;
        cout << "Enter 1:Yes or 0:No : " ;
        cin >> IGiven;
        if (IGiven==1){
            cout<<"Enter Moment of Inertia (I) in mm^4: ";
            cin>>MoI;
        } else {
            cout << "Select shape of cross-section"<<endl;
            cout << "1. Rectangle" << endl;
            cout << "2. Circle" << endl;
            cout << "Enter 1 or 2: ";
            cin >> shapeOfBeam;

            if (shapeOfBeam == 1){
                cout << "You have selected Rectangle" << endl;
                cout << "---------------------------------" << endl;
                cout << "Enter width of rectangle in mm: ";
                cin >> width;
                cout << "Enter depth of rectangle in mm: ";
                cin >> depth;
                MoI = (width * pow(depth,3)) / 12.0;
                cout<< "Calculated Moment of Inertia (I) is "<<MoI<<" mm^4"<<endl;
            } else if (shapeOfBeam == 2){
                cout << "You have selected Circle" << endl;
                cout << "---------------------------------" << endl;
                cout << "Enter diameter of circle in mm: ";
                cin >> depth;
                double sa;
                sa = M_1_PI * pow(depth,2) / 4.0;
                qavg(SF*1000,sa);
            }
        }

        cout << "---------------------------------" << endl;

        cout << "3. Level at which shear stress is to be calculated (y)? :[If Known]"<< endl;
        cout << "Enter 1:Yes or 0:For Ymax : ";
        cin >> yGiven;
        if (yGiven==1){
            cout<<"Enter the value in mm: ";
            cin >> y;
        } else {
            y=depth/2;
            cout<< "y is taken as "<<y<<endl;
        }
        
        cout << "---------------------------------" << endl;

        cout << "4.Shadow Area (As)? :[If Known]"<<endl;
        cout << "Enter 1:Yes or 0:No : ";
        cin >> AsGiven;
        if (AsGiven==1){
            cin >> As;
        } else if (AsGiven==0){ {
            cout << "Calculating Shadow Area (As)..."<<endl;
            cout << "Given width is "<<width<<" mm"<<endl;
            cout << "Given depth is "<<depth<<" mm"<<endl;
            cout << "Given y is "<<y<<" mm"<<endl;
            if (y>depth/2){
                cout<< "Error! y cannot be greater than depth/2"<<endl;
            } else if(y==depth/2){
                As = width * (depth/2);
                cout<< "Calculated Shadow Area (As) is "<<As<<" mm^2"<<endl;
            } else if(y<depth/2){ {
                As = width * (depth/2 - y);
            }
            cout<< "Calculated Shadow Area (As) is "<<As<<" mm^2"<<endl;
        }
        }

        cout << "---------------------------------" << endl;

        cout << "5. What is ybar?[If Known]"<<endl;
        cout << "Enter 1:Yes or 0:No : ";
        cin >> ybarGiven;
        if (ybarGiven==1){
            cin >> y;
        } else if(ybarGiven==0){
            cout << "Enter the given Data to find ybar"<<endl;
            cout << "Is the y at Neutral axis? Enter 1 for yes, 0 for no: ";
            int atNeutral;
            cin >> atNeutral;
            if (atNeutral==1){
                yBar=depth/4;
                cout<< "ybar is taken as "<<yBar<<endl;
                }
            else{
                yBar=((depth/2 - y)/2)+y;
                cout<< "ybar is taken as "<<yBar<<endl;
            }
            
        }

        cout << "---------------------------------" << endl;


        cout << "6. Width of section at level y (b)? [If Known]"<<endl;
        cout << "Enter 1:Yes or 0:No : ";
        cin >> bGiven;
        if (bGiven==1){
            cin >> width;
        } else {
            width=width;
            cout<< "Width (b) is taken as "<<width<<endl;
        }

        
        cout << "---------------------------------" << endl;
        cout<< "Calculating Shear Stress..."<<endl;
        cout << "Given Shear Force (F) is "<<(SF*1000)<<" N"<<endl;
        cout << "Given Moment of Inertia (I) is "<<MoI<<" mm^4"<<endl;
        cout << "Given Shadow Area (As) is "<<As<<" mm^2"<<endl;
        cout << "Given distance ybar is "<<yBar<<" mm"<<endl;
        cout << "Given width (b) is "<<width<<" mm"<<endl;
        SF=SF*1000;
        shearStress = (SF * yBar * As) / (MoI * width);
        cout<< "Calculated Shear Stress is "<<shearStress<<" N/mm^2"<<endl;

    }
}
    
    return 0;
}
