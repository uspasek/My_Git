
/*
function alertMe() {
  alert("Js ")
}
*/
$(document).ready(function(){


  //document.getElementById('text').innerHTML = "This is Js code"; //Js style

  //$('#text').html("This is JQuery code"); //JQuery style

  //$('.my-input').val("That is JQ input")

  //var el = document.getElementById('text');

  //console.log("el in Vanilla Js: ", el);

  //console.log("el in JQuery: ", $(el));

  //document.getElementById('go-button').addEventListener("click", alertMe);
/*
  $("#go-button").on("click", function(){

    console.log("It's jQuery");

  });

  $("#go-button").hover(function(){

    console.log("It's jQuery");

  });
*/
  $("#go-button").on("mousedown", function(){

    console.log("It's jQuery");

  });


});
