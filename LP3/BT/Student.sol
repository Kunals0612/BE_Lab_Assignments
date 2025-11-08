//SPDX-License-Identifier:MIT
pragma solidity ^0.8.0;

contract StudentData{
    //student structure holding information
    struct Student{
        uint id;
        string name;
        uint age;
    }
    
    //array of object
    Student[] public students;
    
    //add student
    function addStudent(uint _id, string memory _name, uint _age) public{
        students.push(Student(_id,_name,_age));
    }
    
    //find student by id
    function getStudentById(uint _id) public view returns(uint, string memory, uint){
        for(uint i = 0; i < students.length; i++){
            if(students[i].id == _id){
                return(students[i].id, students[i].name, students[i].age);
            }
        }
        revert("Student with give id not found");
    }
    
    //find all students
    function getAllStudents() public view returns(Student[] memory){
        return students;
    }

    //delete student by id
    function deleteStudentById(uint _id) public {
        for(uint i = 0; i < students.length; i++){
            if(students[i].id == _id){
                students[i] = students[students.length - 1];
                students.pop();
                return;
            }
        }
        revert("Student with given id not found");
    }

    //editStudentById
    function editStudentById(uint _id, string memory _name, uint _age) public{
        for(uint i = 0; i < students.length; i++){
            if(students[i].id == _id){
                students[i].name = _name;
                students[i].age = _age;
                return;
            }
        }
        revert("Student with given id not found");
    }
    
    //calls when no function matches
    fallback() external payable{}
    
    //plain ether transfer
    receive() external payable{}
}