var totalDeposit = 0;

var Account = function(deposit) {
  totalDeposit = deposit;
};

Account.prototype.getAccount = () => {
  return totalDeposit;
};

Account.prototype.withDraw = (money) => {
  this.money = money;
  totalDeposit -= money;
};

Account.prototype.AtmRemainingCash = () => {
  return this.money;
};

module.exports = Account;