#include "a1solution.h"

#include "dependencies/Eigen/Dense"


using Eigen::MatrixXd;


A1Solution::A1Solution(std::vector<Joint2D*>& joints, std::vector<Link2D*>& links)
    :m_joints(joints),
    m_links(links){

}



void A1Solution::update(Joint2D* selected, QVector2D mouse_pos){

    // Students implement solution here
    //ELements - Joint2d(set, get positions, get children and get parents)(dont have to use get links) to get length of link, substract one joint
    // from the other. Update function is called once in showtimme mode. You have a vector of all joints in h file.
    // Multiple parents or multiple root joints are not checked. But different models are checked.

    // Setup transformation matrix for each individual joint (4x4). You can combine translation and rotation in one 4x4. Each matrix has the angle
    // and length of link. L1 is from corner to first joint. Once this is setup, make fk.
    //fk should return vector<Qvector2D) fk (vector Joint2D* J, starting point), iterate over hierarchy and compute global positions of joints.
    // Only need to update matrix of initial joint, after calling fk, everything will be computed automatically.
    // Eigen has helper functions to generate transformations matrices.

    //store distance and angle of child from parent
    //get new angle (atan2) by adding it (the angle I rotated the parent) childs original angle
    //set new position by doing new parent postion + distance at the new angle

    // Iterate over joint vector and setup transformation matrices for each of them.

    for(const auto& value: m_joints){
        Eigen::Matrix4f mat;
    }

    // If selection has no parent, move entire thing, getPosition from joint file
    Eigen::Matrix4f mat;
    QVector2D parent_node_pos;
    QVector2D new_pos;
    QVector2D diff;


    if(selected->get_parents().size() == 0){
            parent_node_pos = selected->get_position();
            new_pos = selected->get_position();
            diff = mouse_pos - parent_node_pos;

            for(const auto& value: m_joints){
               selected->set_position(mouse_pos);
               value->set_position(value->get_position() + diff);

            }
    }



    // Right way: store transformations matrices for every joint and update them
    // Local transformations matrices 4x4 matrix, with roation and translation(position) combined for each joint
    // Multiply translation from translation you get from the mouse

    // Rotation joint: check picture. Apply theta rotation to transformation matrix of child joints. You can use and eigan function.
    // After you return the position from the FK function, you can update the position of the joints.



}

// FK function should be here.
std::vector<QVector2D> fk(std::vector<Joint2D*>& joints, Joint2D* selected){


    for(const auto& value: joints){
       // value->get_position();
       // Eigen::Matrix4f mat(value);


    }
}

void A1Solution::test_eigen_library(){

    // create a simple matrix 5 by 6
    MatrixXd mat(5,6);

    // Fills in matrix
    for(unsigned int row=0;row<mat.rows();row++){
        for(unsigned int col=0;col<mat.cols();col++){
            mat(row,col) = row+col;
        }
    }

    // create the pseudoinverse
    MatrixXd pseudo_inv = mat.completeOrthogonalDecomposition().pseudoInverse();

    // print the pseudoinverse
    std::cout << "--------------------------" << std::endl;
    std::cout << pseudo_inv << std::endl;
    std::cout << "--------------------------" << std::endl;

}
