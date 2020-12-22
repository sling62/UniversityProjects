$('.button-collapse').sideNav({
      menuWidth: 700, // Default is 240
      closeOnClick: true // Closes side-nav on <a> clicks
    }
  );
  $('.collapsible').collapsible();
  
  /*reloads page and alert message appears when submit button is clicked*/
  function displayMessage()
  {
	  location.reload();
	  alert("Quiz submitted");
  }
  
  
  
   function myFunction() { /*js for quiz section, hide/show on click of lets do it! button*/
    var x = document.getElementById('myDIV');
    if (x.style.display === 'none') {
        x.style.display = 'block';
    } else {
        x.style.display = 'none';
    }
}
	/*nav bar drop down and nav bar mobile collapse js*/
  $(document).ready(function() {
    $('select').material_select();
	$(".button-collapse").sideNav();
	$(".dropdown-button").dropdown();
  });
  
  $(".dropdown-button").dropdown();