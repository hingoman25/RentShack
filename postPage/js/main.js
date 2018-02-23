'use strict';


var messageForm = document.getElementById('messageForm'); //IMPLEMENTED IN HTML
var titlePost = document.getElementById("titlePost"); //IMPLEMENTED IN HTML
var pricePerHour = document.getElementById('pricePerHour'); //IMPLEMENTED IN HTML
var itemDescription = document.getElementById('itemDescription'); //IMPLEMENTED IN HTML
var imageURL = "https://www.google.com/";
/*var submit = document.getElementById('submit');*/ //IMPLEMENTED IN HTML
/*var itemCondition = document.getElementById('inlineRadio1');*/ //IMPLEMENTED IN HTML
/*var fileUpload = document.getElementById('exampleInputFile');*/ //IMPLEMENTED IN HTML

var listeningFirebaseRefs = [];

function setURL(url) {
	imageURL = url;
	console.log("imageURL has been set to" + imageURL);
}


function writeNewPost(uid, username, email, titlePost, itemDescription, pricePerHour, imgURL) {


  // Get a key for a new Post.
  var newPostKey = firebase.database().ref().child('posts').push().key;
  
	// A post entry.
  var postData = {
    uid: uid,
	username: username,
	email: email,
	itemDescription: itemDescription,
	pricePerHour: pricePerHour,
    titlePost: titlePost,
	pid: newPostKey,
	imageURL: imgURL
    //starCount: 0, PERHAPS ADD ITEMAVALIABILITY VARIABLE??? 
  };
  // Write the new post's data simultaneously in the posts list and the user's post list.
  var updates = {};
  updates['/posts/' + newPostKey] = postData;
  updates['/user-posts/' + uid + '/' + newPostKey] = postData;

  return firebase.database().ref().update(updates);
}


function writeUserData(userId, name, email, imageUrl) {
  firebase.database().ref('users/' + userId).set({
    username: name,
    email: email,
    profile_picture : imageUrl
  });
}
  
  var currentUID;

  
function onAuthStateChanged(user) {
  // We ignore token refresh events.
  if (user && currentUID === user.uid) {
    return;
  }

  //cleanupUi();
  if (user) {
	  console.log('this is inside main.js');
	  console.log(user);

    currentUID = user.uid;
    //splashPage.style.display = 'none';
    //writeUserData(user.uid, user.displayName, user.email, user.photoURL);
    //startDatabaseQueries();
  } else {
    // Set currentUID to null.
    currentUID = null;
    // Display the splash page where you can sign-in.
    //splashPage.style.display = '';
  }
}


function newPostForCurrentUser(titlePost, itemDescription, pricePerHour) {
  // [START single_value_read]
  var userId = firebase.auth().currentUser.uid;
  return firebase.database().ref('/users/' + userId).once('value').then(function(snapshot) {
    var username = (snapshot.val() && snapshot.val().username) || 'Anonymous';
    // [START_EXCLUDE]
    return writeNewPost(firebase.auth().currentUser.uid, username, firebase.auth().currentUser.email,
        titlePost, itemDescription, pricePerHour, imageURL);
    // [END_EXCLUDE]
  });
  // [END single_value_read]
}


window.addEventListener('load', function() {

  // Listen for auth state changes
  firebase.auth().onAuthStateChanged(onAuthStateChanged);

  // Saves message on form submit.
  messageForm.onsubmit = function(e) {
    e.preventDefault();
    //var text = messageInput.value;
    //var title = titleInput.value;
	var title = titlePost.value;
	var price = pricePerHour.value;
	var description = itemDescription.value;
	//var condition = itemCondition.value;
	//var upload = fileUpload.value;
	
    //if (text && title) {
	  if ( title && description && price) {
      newPostForCurrentUser(title, description, price).then(function() {
       // myPostsMenuButton.click();
      });
      titlePost.value = '';
	  itemDescription.value = '';

    }
  };
}, false);



