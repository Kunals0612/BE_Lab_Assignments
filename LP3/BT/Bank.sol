//SPDX-License-Identifier:MIT
pragma solidity ^0.8.0;

contract BankAccount{
    mapping(address => uint256) private balance;
    
    event Deposit(address user, uint256 amount);
    event WithDraw(address user, uint256 amount);

    function deposit() public payable{
        balance[msg.sender] += msg.value;
        emit Deposit(msg.sender, msg.value);
    }

    function withDraw(uint256 amount) public {
        require(balance[msg.sender] >= amount, "Insufficient Bank Balance");
        balance[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
        emit WithDraw(msg.sender, amount);
    }

    function getBalance() public view returns (uint256){
        return balance[msg.sender];
    }
}