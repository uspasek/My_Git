var btn = document.getElementById("go-button");
var hobbies = ["reading", "sports", "partying", "traveling"];

function buttonClicked(){
  console.log("Button has been clicked");

  var customText = document.getElementsByClassName("my-input");
  var textArea = document.getElementsByClassName("my-textarea")

  var results = document.getElementById("text");

  results.innerHTML = "Hello, " + customText[0].value + "</br>";

  results.innerHTML += "Message, " + textArea[0].value;
}

btn.addEventListener("click", buttonClicked);


var numbers = [0,3,7,10,6,2,5,9,8,4]


function ugh(numbers){

var missing = -1;

  for (var i = 0; i <= numbers.length; i++)
  {
    console.log(numbers.indexOf(i));
    if(numbers.indexOf(i) === -1)
    {
      missing = i;
    }
  }
  return "tego brakuje -> " + missing ;
}

console.log(ugh(numbers));
