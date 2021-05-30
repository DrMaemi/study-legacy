const mongoose = require('mongoose');

const userSchema = mongoose.Schema({
  name: {
    type: String,
    maxlength: 50
  },
  email: {
    type: String,
    trim: true, // 빈 칸을 없애주는 역할
    unique: 1
  },
  password: {
    type: String,
    minlength: 5
  },
  lastname: {
    type: String,
    maxlength: 50
  },
  role: {
    type: Number, // 1이면 관리자, 0이면 유저 이런 식으로 지정할 수 있음
    default: 0 // 따로 지정하지 않으면 0으로
  },
  image: String,
  token: {
    type: String
  },
  tokenExp: {
    type: Number
  }
});

// 모델은 스키마를 wrap한다. 일단 그렇게 생각
const User = mongoose.model('User', 'userSchema'); 

module.exports = { User };