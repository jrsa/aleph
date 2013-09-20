; a scheme program for generating bitmapped fonts from the GIMP.
; stage 1 of the aleph font process.
; produces a pile of images in .xpm format.					

(define (font_xpm_gen
	 outpath 	; target location
	 font		; font name
	 all		; if set, generate all basic ascii characters, otherwise just numerals
;	 img-w		; initial (max) image width
;	 img-h		; initial (max) image height
	 font-size	; font size
;	 crop-w	; fonts are dumb... its best to arbitrarily crop the output.
;	 crop-h	; 
;	 crop-offx	; 
;	 crop-offy	; 
	 ; now using autocrop
	 )


  (define (draw_text img drawable text font size)
					; start undo group
    (gimp-undo-push-group-start img)
    
    (let * (
	    (text-float (car (gimp-text-fontname
			      img 		; image
			      drawable	; drawable
			      0		; x 
			      0		; y
			      text		; text string
			      0		; size of border
			      1		; antialiasing
			      size		; size in pixels
			      0		; unit (pixels)
			      font		; font name string
			      )))
	    )

      (display "font extents: ")
      (display (gimp-text-get-extents-fontname text size 0 font))
      (display #\newline)
					; anchor selection
      (gimp-floating-sel-anchor text-float)
      
					; finish undo group
      (gimp-undo-push-group-end img)

					; flush output
      (gimp-displays-flush)
      )
    )

  (define (make_char_img char font fontsize)
    (let* (
	   (img (car (gimp-image-new fontsize (* 2 fontsize) RGB)))
	   (layer (car (gimp-layer-new img fontsize (* 2 fontsize)
				       RGB "layer 1" 100 NORMAL)))
;	   (outpath "/home/emb/Desktop/aleph_fonts/")
	   (charstring (if (string=? char ".")
			   "dot"
			   (if (string=? char "/")
			       "slash"
			       char
			       )
			   )
		       )
	   (outstring 
		(string-append "_" (number->string fontsize) "-" charstring ".xpm")
		)
	    )
	   
      (display " rendering glyph at path: ")
      (display (string-append outpath outstring) )
      (display #\newline)

					; add a layer
      (gimp-image-add-layer img layer 0)

					; paint background
      (gimp-palette-set-background '(255 255 255))
      (gimp-edit-fill layer BG-IMAGE-FILL)

					; draw the text
					; in fonts, the size in px represents the maximum baseline between one line and the next.
					; it does NOT represent the actual height of each character.
					; so, this needs to be fudged with arbitrarily different arguments
					; for px height of the output image, and px size of the font
					; ( could modify xpm_convert tool to discard empty columns / rows ? )
      (draw_text img layer char font fontsize)

					; convert to 4-bit indexed
      (gimp-image-convert-indexed img
				  0	; dither:  no dither
				  0	; palette type: generate
				  16	; number of colors
				  0	; alpha dither: no
				  0	; ignore unused (n/a)
				  "none"	; palette name (n/a)
				  )

      ; crop the image ... this is because fonts usually include some padding
;      (gimp-image-crop
;       img
;       crop-w 		; new width
;       crop-h 		; new height
;       crop-offx  		; off-x
;       crop-offy 		; off-y
;      )
      ; autocrop
      (plug-in-autocrop RUN-NONINTERACTIVE img layer)

					; display
      (gimp-display-new img)

					; save
      (gimp-file-save RUN-NONINTERACTIVE
		      img
		      layer
		      (string-append outpath outstring)
		      outstring)
      ))

					; test
					; (make_char_img 14 24 "3" "Arial")

					; long string of all basic ascii characters starting from 0x20 [space]
					; ( let* ( (str "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}"))
					; just numbers
  (let* ( (str (if (= all 1)
		   "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}"
		   "./0123456789"
		   )
	       )
	  )
					; loop through the string
    (define (strdo n) 
					; tail-recurse
      (if (= n 0)
	  n
	  (let* 
	      ( (char (substring str (- n 1) n ) ) )
	    (display char)
	    (display " ")
	    (make_char_img char font font-size)
	    (strdo (- n 1))
	    )    
	  )
      )
    (display str)
    (display " [ size: ")
    (display (string-length str))
    (display " ] ")
    (strdo (string-length str))
    )
)