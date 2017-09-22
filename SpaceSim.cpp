#include <iostream>
#include <vector>
#include "Matrix.hpp"
#include "Plotter.hpp"

using namespace std;

class Circuit;

class Branch
{
public:

    double resistance;
    double inductance;
    double capacitance;
    double voltage;
    double current;

    int inode;
    int jnode;
};

class Circuit
{
public:
    Circuit();
    void AddBranch(Branch& branch, int inode, int jnode);
    void Init();
  
private:
    int nbranch;
    vector<Branch*> branches;
    Matrix Rb, Lb;
};


Circuit::Circuit()
{
    nbranch = 0;
    branches = vector<Branch*>(0);
}

void Circuit::Init()
{
    Rb = Matrix(nbranch);
    Lb = Matrix(nbranch);

    for (unsigned int i=0; i < branches.size(); i++)
    {

    }
}

void Circuit::AddBranch(Branch& branch, int inode, int jnode)
{
    branch.inode = inode;
    branch.jnode = jnode;
    branches.push_back(&branch);
}

int main()
{
    cout << "test circuit";

    Circuit circuit;

    Branch R1, R2, L, C, V;

    R1.resistance = 1.0;
    R2.resistance = 1.0;
    L.inductance = 1.0;
    C.capacitance = 1.0;
    V.voltage = 1.0;

    circuit.AddBranch(R1, 1, 2);
    circuit.AddBranch(R2, 3, 0);
    circuit.AddBranch(L, 2, 3);
    circuit.AddBranch(C, 3, 0);
    circuit.AddBranch(V, 1, 0);

    cin.get();
}
