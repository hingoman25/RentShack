'use strict';


var messageForm = document.getElementById('message-form'); //IMPLEMENTED
var titlePost = document.getElementById('exampleInputEmail1'); //IMPLEMENTED
var pricePerHour = document.getElementById('pricePerHour'); //IMPLEMENTED
var itemDescription = document.getElementById('itemDescription'); //IMPLEMENTED
var submit = document.getElementById('submit'); //IMPLEMENTED
var itemCondition = document.getElementById('inlineRadio1'); //IMPLEMENTED
var fileUpload = document.getElementById('exampleInputFile'); //IMPLEMENTED

var listeningFirebaseRefs = [];


function writeNewPost(uid, username, picture, titlePost, itemDescription) {
  // A post entry.
  var postData = {
    author: username,
    uid: uid,
	itemDescription: itemDescription,
    titlePost: titlePost,
    starCount: 0,
    authorPic: picture
  };

  // Get a key for a new Post.
  var newPostKey = firebase.database().ref().child('posts').push().key;

  // Write the new post's data simultaneously in the posts list and the user's post list.
  var updates = {};
  updates['/posts/' + newPostKey] = postData;
  updates['/user-posts/' + uid + '/' + newPostKey] = postData;

  return firebase.database().ref().update(updates);
}