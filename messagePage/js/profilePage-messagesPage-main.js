//  // Initialize Firebase
'use-strict';

var senderUID;
var receiverUID;
var global_convoID;

var message = document.getElementById('userMessage');
var messageForm = document.getElementById('messageForm');
// /*alert('THIS IS A FUCKING ALERT');*/



// 	document.getElementById('anchor').addEventListener("click", sendInstancePID() );
 


// 	function sendInstancePID() {
// 		alert('I HAVE BEEN CALLED');
// 	}



function assignUIDS(global_uid) {

	firebase.auth().onAuthStateChanged(function(user) {
		senderUID = user.uid;
		receiverUID = global_uid;

		console.log(senderUID + ' is trying to message ' + receiverUID);
		
		localStorage.setItem("senderUID", senderUID);
		localStorage.setItem("receiverUID", receiverUID);

		writeNewConversation();
	});
	
		
}



function writeNewConversation() {

  // Get a key for a new Post.
  var newConversationKey = firebase.database().ref().child('users/' + senderUID).push().key;
  
	// A post entry.
  var conversationData = {
	  uid1: senderUID,
	  uid2: receiverUID
	  
    //starCount: 0, PERHAPS ADD ITEMAVALIABILITY VARIABLE??? 
  };
  // Write the new post's data simultaneously in the posts list and the user's post list.
  var updates = {};
  updates['/users/' + senderUID + '/conversations/' + newConversationKey] = conversationData;
  updates['/users/' + receiverUID + '/conversations/' + newConversationKey] = conversationData;

	firebase.database().ref('users/' + senderUID + '/conversations/' + newConversationKey + '/').remove();
	firebase.database().ref('users/' + receiverUID + '/conversations/' + newConversationKey + '/').remove();
	convoID = newConversationKey;

		//firebase.database().ref('posts/' + pid).remove();

	window.location.assign("../messagePage/messagePage.html?convoid=" + newConversationKey);

	
  return firebase.database().ref().update(updates);
}




function writeNewMessage(uid, username, message) {


  // Get a key for a new Post.
  var newMessageKey = firebase.database().ref().child('users/' + senderUID).push().key;
  
	// A post entry.
  var messageData = {
	  uid: uid,
	  username: username,
	  message: message
	 // isRead: false
    //starCount: 0, PERHAPS ADD ITEMAVALIABILITY VARIABLE??? 
  };
  // Write the new post's data simultaneously in the posts list and the user's post list.
  var updates = {};
  updates['users/' + currentUID + '/conversations/' + global_convoID + '/' + newMessageKey] = messageData;
  updates['users/' + localStorage.getItem("receiverUID") + '/conversations/' + global_convoID + '/' + newMessageKey] = messageData;

	//alert('user ' + localStorage.getItem("senderUID"));
	
	
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

function newMessageForCurrentUser(message) {
  var userId = firebase.auth().currentUser.uid;
  return firebase.database().ref('/users/' + userId).once('value').then(function(snapshot) {
    var username = (snapshot.val() && snapshot.val().username);
	 // var profilePic = (snapshot.val() && snapshot.val().profilePic)
    return writeNewMessage(firebase.auth().currentUser.uid, username, message);;
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

	global_convoID = sliceConvoID();
	
  // Listen for auth state changes
  firebase.auth().onAuthStateChanged(onAuthStateChanged);

  // Saves message on form submit.
  messageForm.onsubmit = function(e) {
    e.preventDefault();
    //var text = messageInput.value;
    //var title = titleInput.value;
	var messageVar = message.value;
	//var price = pricePerHour.value;
	//var description = itemDescription.value;
	//var condition = itemCondition.value;
	//var upload = fileUpload.value;
	
    //if (text && title) {
	  if ( messageVar ) {
      newMessageForCurrentUser(messageVar).then(function() {
       // myPostsMenuButton.click();
      });
      messageVar.value = '';

    }
  };
}, false);

function sliceConvoID() {
    var currentURL = window.location.href;
	var index = currentURL.indexOf("=" , 0) + 1;
	
	var convoID = "";
	for(var i = index; i < currentURL.length; i++)
	{
			
		convoID += currentURL.charAt(i);

	}
	global_convoID = convoID;
	return convoID;
}

