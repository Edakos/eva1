
/**
 * Client side file input validation.
 */
Drupal.behaviors.importerUploadValidate = function(context) {
  $("input[type='file'][accept]", context).change( function() {
    // Remove any previous errors.
    $('.importer-js-error').remove();

    /**
     * Add client side validation for the input[type=file] accept attribute.
     */
    var accept = this.accept.replace(/,\s*/g, '|');
    if (accept.length > 1 && this.value.length > 0) {
      var v = new RegExp('\\.(' + accept + ')$', 'gi');
      if (!v.test(this.value)) {
        var error = Drupal.t("The selected file %filename can not be uploaded. Only files with the following extensions are allowed: %extensions.",
          { '%filename' : this.value, '%extensions' : accept.replace(/\|/g, ', ') }
        );
        // What do I prepend this to?
        $(this).before('<div class="messages error importer-js-error">' + error + '</div>');
        this.value = '';
        return false;
      }
    }
  });
};