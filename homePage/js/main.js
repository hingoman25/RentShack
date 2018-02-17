'use strict';


var titlePost = document.getElementById('titlePost');
var itemDescription = document.getElementById('itemDescription');


// var ref = firebase.database().ref();

// ref.on("value", function(snapshot) {
// 	console.log(snapshot.val());
// }, function (error) {
// 	console.log("Error: " + error.code);
// });


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


