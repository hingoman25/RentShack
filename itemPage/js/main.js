'use strict';


var titlePost = document.getElementById('titlePost');
var itemDescription = document.getElementById('itemDescription');


var playersRef = firebase.database().ref("/posts");

playersRef.on("child_added", function(data, prevChildKey) {
   var user = data.val();
   console.log("title: " + user.titlePost);
   console.log("description: " + user.itemDescription);

});

function slicePID() {
    var currentURL = window.location.href;
	var index = currentURL.indexOf("=" , 0) + 1;
	
	var pid = "";
	for(var i = index; i < currentURL.length; i++)
	{
			
		pid += currentURL.charAt(i);
		console.log(pid);

	}
	
	return pid;
}


function populatePost( pid ) {
	
	return firebase.database().ref('/posts/' + pid).once('value').then(function(snapshot) {
  			var titlePost = (snapshot.val() && snapshot.val().titlePost);
			var itemDescription = (snapshot.val() && snapshot.val().itemDescription);
			var pricePerHour = (snapshot.val() && snapshot.val().pricePerHour);
			var postPicture  = (snapshot.val() && snapshot.val().imageURL);
		
			document.getElementById('postTitle').innerHTML = titlePost;
			document.getElementById('postPrice').innerHTML = "$" + pricePerHour + " /hour";
			document.getElementById('postDescription').innerHTML = itemDescription;
			document.getElementById('postPicture').src = postPicture;
  			/*document.getElementById('username').innerHTML = username;
			document.getElementById('profilePic').src = (snapshot.val() && snapshot.val().profilePic);*/

		  });		
	
	
}

function showComment(){
	var x = document.getElementById("commentForm");
    if (x.style.display === "none") {
        x.style.display = "block";
		window.scrollBy(0,200);
	}
}


window.onload = function() {
	var pid = slicePID();
	
	populatePost(pid);
};

