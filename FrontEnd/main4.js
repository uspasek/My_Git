
/*
function alertMe() {
  alert("Js ")
}
*/
//this is jQuery code
$(document).ready(function(){

  //simple console.log function
  function printMe(){
    console.log($(this).text());
  }
  //stops from right click showing contextmenu
  $(document).on('contextmenu', function(){
    return false;
  });

  $(document).on('mousedown',function(event1){

    event1.stopPropagation();

    if(event1.which == 3){

      $('.hidden').removeClass('shown');
      //to show extra options on img right click
      if($(event1.target).is('img')){

        $('.saveimg, .newtab').addClass('shown');

      }else if($(event1.target).is('a')){

        $('.newtab').addClass('shown');

      }

      console.log(event1.pageX, event1.pageY);

      $('#context').css({
        top: event1.pageY,
        left: event1.pageX
      });
      // fading of contenxt menu
      $('#context').fadeIn();
      return false;

    }
      $('#context').fadeOut();


    /*
    switch(event1.which){

      case 1:
        console.log("Clicked left");
        break;
      case 3:
        console.log("Clicked right");
        break;

    }
    */
  });
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

  $("#go-button").on("mousedown", function(){

    console.log("It's jQuery");

  });
*/

//creating a dropdown menu
  /*
  $('[data-trigger="dropdown"]').on('mouseenter',function(){
      var submenu = $(this).parent().find('.submenu');
      submenu.addClass('active');

  $('.profile-menu').on('mouseleave',function(){

    submenu.removeClass('active');
  });
  });
  */
  $('[href="https://www.tech-med.com.pl"]').on("click", function(event){
    //preventing from default site opening on click on the link
    //event.preventDefault();
    return false; //works the same way

  });
  //dropdown with a fade
  $('[data-trigger="dropdown"]').on('mouseenter',function(){
      var submenu = $(this).parent().find('.submenu');
      submenu.fadeIn(200);

  $('.profile-menu').on('mouseleave',function(){

    submenu.fadeOut(300);
  });
  });

  //action occurring on an event                //event
  $('#append, #prepend, #replace').on('click', function(e){

    var el = $(e.currentTarget);
    var action = el.attr('id'); //attribiute
    var content = $('.text').val();

    if(action == "prepend"){

      console.log("P");
      $('#main').prepend(content);

    }else if (action == "append"){

      console.log("A");
      $('#main').append(content);

    }else if (action == "replace"){

      console.log("R");
      $('#main').html(content);

    }
    //clear input after any of PAR
    $('.text').val('');
  });

  //changes is to ------------->
  $('p:contains("Lorem")').html("This is Lorem");

  //checking for Lorem in a paragraph
  if($(':contains("Lorem")').is("p")){
    console.log("Its in a paragraph");
  }
  //checking for Lorem in a div
  else if($(':contains("Lorem")').is("div")){
    console.log("Its in a div");
  }

  //checking if the Lorem thing has a Class
  if($(':contains("Lorem")').hasClass("my-selector")){
    console.log("It has a Class");
  }

  //each, works like a loop for certain objects
  $('p').each(function(){
    console.log($(this).text());
  });
  //using a printMe function to loop through paragraphs
  $('p').each(printMe);

  //when fousing on an object console.log it
  $('.email').focusin(function(){

    console.log("foused in on textarea");

  });

  $('.email').focusout(function(){

    console.log("foused out on textarea");

  });

  $('.email').focusout(function(){
    if(($(this).val().indexOf("@")) > -1 && ($(this).val().indexOf(".") > -1)){
      $('.status').html("valid email");
    }else{
      $('.status').html("invalid");
    }
  });

  /*
  //css in JS
  $('input').css({
    color: 'yellow',
    borderColor: 'red'
  });
  */

});
