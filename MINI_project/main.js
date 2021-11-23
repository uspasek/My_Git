
var value1 = 0;
var value2 = 0;
var result;

function add_element(){

  value1 = document.getElementById("text1").value;
  value2 = document.getElementById("text2").value;

  result =  Number(value1) + Number(value2);

  document.getElementById("result").innerHTML = "Result -> " + result;

}

function sub_element(){

  value1 = document.getElementById("text3").value;
  value2 = document.getElementById("text4").value;

  result =  Number(value1) - Number(value2);

  document.getElementById("result2").innerHTML = "Result -> " + result;

}

function multi_element(){

  value1 = document.getElementById("text3").value;
  value2 = document.getElementById("text4").value;

  result =  Number(value1) * Number(value2);

  document.getElementById("result3").innerHTML = "Result -> " + result;

}

function div_element(){

  value1 = document.getElementById("text3").value;
  value2 = document.getElementById("text4").value;

  result =  Number(value1) / Number(value2);

  document.getElementById("result4").innerHTML = "Result -> " + result;

}
