;; (package-initialize)

;; (require 'auto-complete-config)
;; (defun auto-complete-mode-maybe ()
;;   "No maybe for you. Only AC!"
;;   (unless (minibufferp (current-buffer))
;;     (auto-complete-mode 1)))
;; (global-auto-complete-mode t)
;; (setq ac-delay 1)
;; (setq ac-auto-show-menu 0.25)


;;; XEmacs backwards compatibility file
(setq user-init-file
      (expand-file-name "init.el"
			(expand-file-name ".xemacs" "~")))
(setq custom-file
      (expand-file-name "custom.el"
			(expand-file-name ".xemacs" "~")))



(load-file user-init-file)
(load-file custom-file)
(load "/usr/local/share/emacs/PLScript_mode.el")

;;; remove the key to push to background, it's just annoying!
(global-unset-key (kbd "C-z"))
(global-unset-key (kbd "C-x C-z"))

(global-set-key (kbd "C-c i") 'indent-region)
(global-set-key (kbd "C-c c") 'comment-region)
(global-set-key (kbd "C-c u") 'uncomment-region)
(global-set-key (kbd "C-x C-q") 'vc-toggle-read-only)
(global-set-key (kbd "C-x t") 'plscript-insert-tag)
(global-set-key (kbd "C-x m") 'plscript-insert-make)
(global-set-key (kbd "C-x p") 'plscript-insert-get_property)
(global-set-key (kbd "C-x e") 'plscript-insert-page-elem)
(global-set-key (kbd "C-x d") 'plscript-insert-page-dynamic)
(global-set-key (kbd "M-g") 'goto-line)
(global-set-key (kbd "RET") 'newline-and-indent)
(global-set-key (kbd "<backtab>") 'dabbrev-expand)

;;;(if (fboundp 'tool-bar-mode) (tool-bar-mode -1))
;;;(if (fboundp 'scroll-bar-mode) (scroll-bar-mode -1))
;;;(if (fboundp 'menu-bar-mode) (menu-bar-mode -1))

(setq scroll-step 3)

(defun really-no-bell ()
"Do nothing so the bell won't ring even when emacs tries..."
   (interactive) )
(setq visible-bell nil)
(setq ring-bell-function 'really-no-bell)

(blink-cursor-mode nil)

(if (>= (string-to-number (car (split-string emacs-version "\\."))) 23)
    (defun vc-toggle-read-only (&optional verbose)
      "Change read-only status of current buffer, perhaps via version control.
If the buffer is visiting a file registered with version control,
then check the file in or out.  Otherwise, just change the read-only flag
of the buffer.
With prefix argument, ask for version number to check in or check out.
Check-out of a specified version number does not lock the file;
to do that, use this command a second time with no argument."
      (interactive "P") 
      (if (vc-backend buffer-file-name) 
	  (vc-next-action nil)
	(toggle-read-only))))


;;; added by Denny:
(defun backward-kill-line (arg)
  "Kill ARG lines backward."
  (interactive "p")
  (kill-line (- 1 arg)))
(global-set-key (kbd "M-k") 'backward-kill-line)
(global-set-key (kbd "C-p") 'plscript-add-break-point)



(custom-set-variables)

;;; Automatically save and restore sessions
(setq desktop-dirname             "~/.emacs.d/desktop/"
      desktop-base-file-name      "emacs.desktop"
      desktop-base-lock-name      "lock"
      desktop-path                (list desktop-dirname)
      desktop-save                t
      desktop-load-locked-desktop nil)


(defun my-desktop ()
  "Load the desktop and enable autosaving"
  (interactive)
  (let ((desktop-load-locked-desktop "ask"))
    (font-lock-mode 1)
    (desktop-read)
    (desktop-save-mode 1)))

(defun get-prop ()
  "converts a property lookup to a get_property"
  (interactive)
  (search-backward-regexp "[^a-zA-Z0-9_\.]")
  (forward-char)
  (insert-string "get_property(")
  (search-forward ".")
  (backward-delete-char 1)
  (insert-string ",\"")
  (search-forward-regexp "[^a-zA-Z0-9_\.]")
  (backward-char)
  (insert-string "\")"))

;;; multiple cursors
;; (require 'multiple-cursors)
(global-set-key (kbd "C-c C-S-c") 'mc/edit-lines)
(global-set-key (kbd "C->") 'mc/mark-next-like-this)
(global-set-key (kbd "C-<") 'mc/mark-previous-like-this)
(global-set-key (kbd "C-c C-<") 'mc/mark-all-like-this)


;; ;;; just for funsies
;; (load "~/.emacs.d/fireplace/fireplace")


;; Avery's Additions

;; Ace window shortcut 
;; (global-set-key (kbd "M-p") 'ace-window)

;; (package-initialize)
;; (require 'diff-hl)
;; (global-diff-hl-mode)
;; (setq diff-switches '("-u"))

;; ;; hide/show code folding
;; (add-hook 'c++-mode-common-hook
;;   (lambda()
;;     (local-set-key (kbd "C-c <right>") 'hs-show-block)
;;     (local-set-key (kbd "C-c <left>")  'hs-hide-block)
;;     (local-set-key (kbd "C-c <up>")    'hs-hide-all)
;;     (local-set-key (kbd "C-c <down>")  'hs-show-all)
;;     (hs-minor-mode t)))




;; pl_git stuff ... THANKS ALEX!
;; (load "~/vc_tools/emacs/pl_git.el")
