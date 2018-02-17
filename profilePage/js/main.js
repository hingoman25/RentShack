'use strict';


var playersRef = firebase.database().ref("/users");

playersRef.on("child_added", function(data, prevChildKey) {
   var user = data.val();
   console.log("title: " + user.username);
   console.log("description: " + user.email);

   var username = document.getElementById('username').innerHTML =
   user.username;

});