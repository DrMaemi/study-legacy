var assert = require('assert');
var Atm = require('./atm.js');
var atm = new Atm(5000);

describe('Feature: get cash from an ATM:', () => {
  context('Scenario: success', () => {
    describe('When the user asks the ATM for $500', () => {
      atm.withDraw(500);
      it('Then the ATM will have $500', () => {
        assert.equal(atm.AtmRemainingCash(), 500);
      });
      it("Then the user's account will have $4500", function(done) {
        assert.equal(atm.getAccount(), 4500);
        done();
      });
    });
  });
});