'use strict';


var titlePost = document.getElementById('titlePost');
var itemDescription = document.getElementById('itemDescription');


var playersRef = firebase.database().ref("/posts");

playersRef.on("child_added", function(data, prevChildKey) {
   var user = data.val();
   console.log("title: " + user.titlePost);
   console.log("description: " + user.itemDescription);

   var titlePost = document.getElementById('titlePost').innerHTML =
   user.titlePost;

   var itemDescription = document.getElementById('itemDescription').innerHTML =
   user.itemDescription;

});


