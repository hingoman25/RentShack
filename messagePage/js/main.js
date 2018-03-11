'use strict';


/*var titlePost = document.getElementById('titlePost');
var itemDescription = document.getElementById('itemDescription');

var messageForm = document.getElementById('messageForm');
var comment = document.getElementById('userComment');

var playersRef = firebase.database().ref("/posts");*/

var global_uid;
/*
playersRef.on("child_added", function(data, prevChildKey) {
   var user = data.val();


});

function sliceUID() {
    var currentURL = window.location.href;
	var index = currentURL.indexOf("=" , 0) + 1;
	if(index == 0)
		return '';
	var uid = "";
	for(var i = index; i < currentURL.length; i++)
	{
			
		uid += currentURL.charAt(i);

	}
	global_uid = uid;
	return uid;
}

	




function showComment(){
	var x = document.getElementById("commentForm");
    if (x.style.display === "none") {
        x.style.display = "block";
		window.scrollBy(0,200);
	}
}


function writeNewComment(uid, username, profilePic, pid, comment) {


  // Get a key for a new Post.
  var newCommentKey = firebase.database().ref().child('posts/' + pid).push().key;
  
	// A post entry.
  var commentData = {
   uid: uid,
	 cid: newCommentKey,
	 username: username,
	 profilePic: profilePic,
	 comment: comment
    //starCount: 0, PERHAPS ADD ITEMAVALIABILITY VARIABLE??? 
  };
  // Write the new post's data simultaneously in the posts list and the user's post list.
  var updates = {};
  updates['/posts/' + pid + '/post-comments/' + newCommentKey] = commentData;

  return firebase.database().ref().update(updates);
}

  var currentUID;


function onAuthStateChanged(user) {
  // We ignore token refresh events.
  if (user && currentUID === user.uid) {
    return;
  }

  //cleanupUi();
  if (user) {

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

function newCommentForCurrentUser(comment) {

  var userId = firebase.auth().currentUser.uid;
  return firebase.database().ref('/users/' + userId).once('value').then(function(snapshot) {
    var username = (snapshot.val() && snapshot.val().username) || 'Anonymous';
	  var profilePic = (snapshot.val() && snapshot.val().profilePic)
    return writeNewComment(firebase.auth().currentUser.uid, username, profilePic, global_pid, comment);
  });

}


window.addEventListener('load', function() {
  // Bind Sign in button.
 /* signInButton.addEventListener('click', function() {
    var provider = new firebase.auth.GoogleAuthProvider();
    firebase.auth().signInWithPopup(provider);
  }); */

  // Bind Sign out button.
 /* signOutButton.addEventListener('click', function() {
    firebase.auth().signOut();
  }); */

  // Listen for auth state changes
/*  firebase.auth().onAuthStateChanged(onAuthStateChanged);

  // Saves message on form submit.
  messageForm.onsubmit = function(e) {
    e.preventDefault();
    //var text = messageInput.value;
    //var title = titleInput.value;
	var commentVar = comment.value;
	//var price = pricePerHour.value;
	//var description = itemDescription.value;
	//var condition = itemCondition.value;
	//var upload = fileUpload.value;
	
    //if (text && title) {
	  if ( commentVar ) {
      newCommentForCurrentUser(commentVar).then(function() {
       // myPostsMenuButton.click();
      });
      comment.value = '';

    }
  };
}, false);

*/

function snapshotToArray(snapshot) {
    var returnArr = [];

    snapshot.forEach(function(childSnapshot) {
		if(typeof childSnapshot.val() == "object")
		{
			var item = childSnapshot.val();
			item.key = childSnapshot.key;

			returnArr.push(item);
		}
    });
    return returnArr;
}


firebase.database().ref('/users').on('value', function(snapshot) {
    var arr = snapshotToArray(snapshot);
    var convos = document.getElementById('convoList');
    convos.innerHTML = '';
    for(var i = arr.length-1; i >= 0; i--) {
		if(currentUID == arr[i].uid) {
  	    var username;
		var profilePic;
		var uid;	
        var n = Object.values(arr[i]);
        var m = Object.values(n[0]);
			
		var test;
			
        for(var j = m.length-1; j >= 0; j--) {
			
		if(m[j].uid1 == currentUID)
		{ uid = m[j].uid2; }
		else
		{ uid = m[j].uid1; }	
			
			
			
		firebase.database().ref('/users/' + uid).once('value').then(function(snapshot) {
			username = (snapshot.val() && snapshot.val().username);
			profilePic = (snapshot.val() && snapshot.val().profilePic);
          convos.innerHTML += 
         '<a id="anchor" style="text-decoration:none" style="display:block" href="../profilePage/profilePage.html?uid=' + uid + '">' +
                 '<div style="padding: 5px 0px;" class="col-md-offset-2">' +
                              '<div class="col-12 col-lg-4">' +
                                  '<div class="card features">' +
                                      '<div class="card-body">' +
                                          '<div class="media">' +
                                              '<img style="width: 70px; height: 70px; padding-right: 7px; border-radius: 100%;" class="renting" id="image" src=' + profilePic + ' class="listpics" alt="">' +
                                              '<div class="media-body">' +
                                                  '<h4 class="card-title" id="titlePost">' + username + '</h4>' +
                                                  '<p class="card-text" id="itemDescription">' + /*m[j].comment*/ + '</p>' +
                                              '</div>' +
                                          '</div>' +
                                      '</div>' +
                                  '</div>' +
                              '</div>' +
                          '</div>' +
         '</a>';
			});
        }
          
		}
    }
});
/*
firebase.database().ref('/users').on('value', function(snapshot) {
    var arr = snapshotToArray(snapshot);
    var convos = document.getElementById('convoList');
    convos.innerHTML = '';
    for(var i = arr.length-1; i >= 0; i--) {
		if(currentUID == arr[i].uid) {
  	    var userPic = arr[i].profilePic;
  	    var user_name = arr[i].username;
		var uid = arr[i].uid;
        var n = Object.values(arr[i]);
        var m = Object.values(n[0]);
        for(var j = m.length-1; j >= 0; j--) {
          convos.innerHTML += 
         '<a id="anchor" style="text-decoration:none" style="display:block" href="../profilePage/profilePage.html?uid=' + m[j].uid + '">' +
                 '<div style="padding: 5px 0px;" class="col-md-offset-2">' +
                              '<div class="col-12 col-lg-4">' +
                                  '<div class="card features">' +
                                      '<div class="card-body">' +
                                          '<div class="media">' +
                                              '<img style="width: 70px; height: 70px; padding-right: 7px; border-radius: 100%;" class="renting" id="image" src=' + m[j].profilePic + ' class="listpics" alt="">' +
                                              '<div class="media-body">' +
                                                  '<h4 class="card-title" id="titlePost">' + m[j].username + '</h4>' +
                                                  '<p class="card-text" id="itemDescription">' + m[j].comment + '</p>' +
                                              '</div>' +
                                          '</div>' +
                                      '</div>' +
                                  '</div>' +
                              '</div>' +
                          '</div>' +
         '</a>';
        }
          
		}
      }
});*/
/*
window.onload = function() {
	var uid = sliceUID();
	if(uid.length > 0){
		return firebase.database().ref('/users/' + uid).once('value').then(function(snapshot) {
			var username = (snapshot.val() && snapshot.val().username) || 'Anonymous';
			document.getElementById('messagesHeader').innerHTML = "Messaging " + username;

	  	});
	}
};
*/
