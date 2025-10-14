//Assignment No : 6
//Name : Mitkari Sarthak Shivaraj
//Roll No : A-61
#include <iostream>
#include <cmath>
using namespace std;
// Function to calculate and display average and max shear stress
void qavg(double sf, double sa) {
    double shearStress = sf / sa;
    cout << "Average Shear Stress is " << shearStress << " N/mm^2" << endl;
    cout << "Maximum Shear Stress is " << (4.0 / 3.0) * shearStress << " N/mm^2" << endl;
}
int main() {
    // Beam Shear and Bending Stress Calculator
    int width, depth, y;
    int shapeOfBeam, stressSelected;
    double SF, BendingStress, MoI, As, yBar;
    double bendingMoment, shearStress;
    bool beam, center, typeofload, all;
    int BMGiven, IGiven, sigmaGiven, yGiven, SFGiven, AsGiven, bGiven, ybarGiven;

    cout << "Beam Stress Calculator\n";
    cout << "What do you want to calculate?\n1. Shear Stress\n2. Bending Stress\nEnter 1 or 2: ";
    cin >> stressSelected;

    if (stressSelected == 2) {
        cout << "Is Bending Moment (M) given? (1:Yes, 0:No): ";
        cin >> BMGiven;
        if (BMGiven == 1) {
            cout << "Enter Bending Moment (M) in kNm: ";
            cin >> bendingMoment;
        } else {
            cout << "Enter type of beam (1 for simply supported, 0 for cantilever): ";
            cin >> beam;
            double load, length;
            double a, b;

            if (beam) {  // Simply supported beam
                cout << "Type of load (1 for point load, 0 for UDL): ";
                cin >> typeofload;
                if (typeofload) {  // Point Load
                    cout << "Enter load (kN): ";
                    cin >> load;
                    cout << "Enter span length (m): ";
                    cin >> length;
                    cout << "Is load at center? (1:Yes, 0:No): ";
                    cin >> center;
                    if (center) {
                        bendingMoment = (load * length) / 4.0;
                    } else {
                        cout << "Enter distance 'a' from left support (m): ";
                        cin >> a;
                        b = length - a;
                        bendingMoment = (load * a * b) / length;
                    }
                } else {  // UDL
                    cout << "Enter load (kN/m): ";
                    cin >> load;
                    cout << "Is load covering entire span? (1:Yes, 0:No): ";
                    cin >> all;
                    if (all) {
                        cout << "Enter span length (m): ";
                        cin >> length;
                        bendingMoment = (load * length * length) / 8.0;
                    } else {
                        cout << "Enter span length (m): ";
                        cin >> length;
                        cout << "Enter distance 'a' from left support to start of load (m): ";
                        cin >> a;
                        cout << "Enter distance 'b' from right support to end of load (m): ";
                        cin >> b;
                        double loadLength = length - a - b;
                        bendingMoment = (load * loadLength * (length - b) * (length - b)) / (2 * length);
                    }
                }
            } else { // Cantilever beam
                cout << "Enter span length (m): ";
                cin >> length;
                cout << "Type of load (1 for point load, 0 for UDL): ";
                cin >> typeofload;
                if (typeofload) { // Point load
                    cout << "Enter load (kN): ";
                    cin >> load;
                    cout << "Is load at free end? (1:Yes, 0:No): ";
                    cin >> center;
                    if (center) {
                        a = length;
                    } else {
                        cout << "Enter distance 'a' from fixed support (m): ";
                        cin >> a;
                    }
                    bendingMoment = load * a;
                } else { // UDL
                    cout << "Enter load (kN/m): ";
                    cin >> load;
                    cout << "Is load covering entire span? (1:Yes, 0:No): ";
                    cin >> all;
                    if (all) {
                        bendingMoment = (load * length * length) / 2.0;
                    } else {
                        cout << "Enter distance 'a' from fixed support to start of load (m): ";
                        cin >> a;
                        cout << "Enter distance 'b' from free end to end of load (m): ";
                        cin >> b;
                        double loadLength = length - a - b;
                        bendingMoment = load * loadLength * (length - b) / 2.0;
                    }
                }
            }
        }

        cout << "Is Moment of Inertia (I) given? (1:Yes, 0:No): ";
        cin >> IGiven;
        if (IGiven == 1) {
            cout << "Enter Moment of Inertia (I) in mm^4: ";
            cin >> MoI;
        } else {
            cout << "Select shape of cross-section (1: Rectangle, 2: Circle): ";
            cin >> shapeOfBeam;
            if (shapeOfBeam == 1) {
                cout << "Enter width (mm): ";
                cin >> width;
                cout << "Enter depth (mm): ";
                cin >> depth;
                MoI = (width * pow(depth, 3)) / 12.0;
            } else if (shapeOfBeam == 2) {
                cout << "Enter diameter (mm): ";
                cin >> depth;
                MoI = (M_PI * pow(depth, 4)) / 64.0;
            }
        }

        cout << "Is distance y from neutral axis given? (1:Yes, 0:No): ";
        cin >> yGiven;
        if (yGiven == 1) {
            cout << "Enter y (mm): ";
            cin >> y;
        } else {
            y = depth / 2;
            cout << "y is taken as " << y << " mm\n";
        }

        cout << "Is Bending Stress (σ) given? (1:Yes, 0:No): ";
        cin >> sigmaGiven;
        if (sigmaGiven == 1) {
            cout << "Enter Bending Stress (N/mm^2): ";
            cin >> BendingStress;
            cout << "Bending Stress is given as " << BendingStress << " N/mm^2\n";
        } else {
            BendingStress = ((bendingMoment * 1e6) * y) / MoI;
            cout << "Calculated Bending Stress is " << BendingStress << " N/mm^2\n";
        }
    } else if (stressSelected == 1) {
        cout << "Shear Stress Calculator\n";
        cout << "Is Shear Force (SF) given? (1:Yes, 0:No): ";
        cin >> SFGiven;
        if (SFGiven == 1) {
            cout << "Enter Shear Force (kN): ";
            cin >> SF;
        } else {
            cout << "Enter type of beam (1:Simply supported, 0:Cantilever): ";
            cin >> beam;
            cout << "Enter type of load (1:Point load, 0:UDL): ";
            cin >> typeofload;
            double load, length, a, b;
            if (beam) {
                cout << "Enter span length (m): ";
                cin >> length;
                if (typeofload) {
                    cout << "Enter load (kN): ";
                    cin >> load;
                    cout << "Is load at center? (1:Yes, 0:No): ";
                    cin >> center;
                    if (center) {
                        SF = load / 2.0;
                    } else {
                        cout << "Enter distance 'a' from left support (m): ";
                        cin >> a;
                        b = length - a;
                        SF = (load * b) / length;
                    }
                } else {
                    cout << "Enter load (kN/m): ";
                    cin >> load;
                    cout << "Is load covering entire span? (1:Yes, 0:No): ";
                    cin >> all;
                    if (all) {
                        SF = (load * length) / 2.0;
                    } else {
                        cout << "Enter distance 'a' from left support to start of load (m): ";
                        cin >> a;
                        cout << "Enter distance 'b' from right support to end of load (m): ";
                        cin >> b;
                        double loadLength = length - a - b;
                        SF = load * loadLength * (length - b) / length;
                    }
                }
            } else {
                cout << "Enter span length (m): ";
                cin >> length;
                if (typeofload) {
                    cout << "Enter load (kN): ";
                    cin >> load;
                    cout << "Is load at free end? (1:Yes, 0:No): ";
                    cin >> center;
                    if (center) {
                        a = length;
                    } else {
                        cout << "Enter distance 'a' from fixed support (m): ";
                        cin >> a;
                    }
                    SF = load;
                } else {
                    cout << "Enter load (kN/m): ";
                    cin >> load;
                    cout << "Is load covering entire span? (1:Yes, 0:No): ";
                    cin >> all;
                    if (all) {
                        SF = load * length;
                    } else {
                        cout << "Enter distance 'a' from fixed support to start of load (m): ";
                        cin >> a;
                        cout << "Enter distance 'b' from free end to end of load (m): ";
                        cin >> b;
                        double loadLength = length - a - b;
                        SF = load * loadLength;
                    }
                }
            }
            cout << "Calculated Shear Force: " << SF << " kN\n";
        }

        cout << "Is Moment of Inertia (I) given? (1:Yes, 0:No): ";
        cin >> IGiven;
        if (IGiven == 1) {
            cout << "Enter Moment of Inertia (I) in mm^4: ";
            cin >> MoI;
        } else {
            cout << "Select shape of cross-section (1: Rectangle, 2: Circle): ";
            cin >> shapeOfBeam;
            if (shapeOfBeam == 1) {
                cout << "Enter width (mm): ";
                cin >> width;
                cout << "Enter depth (mm): ";
                cin >> depth;
                MoI = (width * pow(depth, 3)) / 12.0;
                cout << "Calculated Moment of Inertia (I) is " << MoI << " mm^4\n";
            } else if (shapeOfBeam == 2) {
                cout << "Enter diameter (mm): ";
                cin >> depth;
                double sa = M_1_PI * pow(depth, 2) / 4.0;
                qavg(SF * 1000, sa);
            }
        }

        cout << "Is level y for shear stress known? (1:Yes, 0:No for ymax): ";
        cin >> yGiven;
        if (yGiven == 1) {
            cout << "Enter y (mm): ";
            cin >> y;
        } else {
            y = depth / 2;
            cout << "y is taken as " << y << " mm\n";
        }

        cout << "Is Shadow Area (As) known? (1:Yes, 0:No): ";
        cin >> AsGiven;
        if (AsGiven == 1) {
            cout << "Enter Shadow Area (As) in mm^2: ";
            cin >> As;
        } else {
            cout << "Calculating Shadow Area (As)...\n";
            if (y > depth / 2) {
                cout << "Error! y cannot be greater than depth/2\n";
            } else if (y == depth / 2) {
                As = width * (depth / 2);
            } else {
                As = width * (depth / 2 - y);
            }
            cout << "Calculated Shadow Area (As) is " << As << " mm^2\n";
        }

        cout << "Is ybar known? (1:Yes, 0:No): ";
        cin >> ybarGiven;
        if (ybarGiven == 1) {
            cout << "Enter ybar (mm): ";
            cin >> yBar;
        } else {
            int atNeutral;
            cout << "Is ybar at neutral axis? (1:Yes, 0:No): ";
            cin >> atNeutral;
            if (atNeutral == 1) {
                yBar = depth / 4;
            } else {
                yBar = ((depth / 2 - y) / 2) + y;
            }
            cout << "ybar is taken as " << yBar << " mm\n";
        }

        cout << "Is width b at level y known? (1:Yes, 0:No): ";
        cin >> bGiven;
        if (bGiven == 1) {
            cout << "Enter width b (mm): ";
            cin >> width;
        } else {
            cout << "Width b is taken as " << width << " mm\n";
        }

        SF = SF * 1000; // convert kN to N
        shearStress = (SF * yBar * As) / (MoI * width);
        cout << "Calculated Shear Stress is " << shearStress << " N/mm^2\n";
    }

    return 0;
}
