$(document).ready(function() {
  $('div.postCommentsBarMax').hide();
  $('div.postCommentsBarAddButton').hide();
  $('textarea.addComment').click(function() {
    $('div.postCommentsBarMax').fadeIn('10');
    $('div.postCommentsBarAddButton').fadeIn('10');
  });
});

$('textarea.addComment').keyup(function () {
    var left = 500 - $(this).val().length;
    if (left < 0) {
    left = 0;
    }
    $('#counter').text('Characters Left: ' + left);
});

$(document).ready(function() {
  $('div.postComments').hide();
  $('a#commentsShow').toggle(function() {
    $('div.postComments').slideDown('100');
    return false;
    },
    function() {
      $('div.postComments').slideUp('100');
      $('div.postCommentsBarMax').slideUp('10');
      $('div.postCommentsBarAddButton').slideUp('10');
      return false;
    });
});
