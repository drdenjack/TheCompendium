
;; Added by Package.el.  This must come before configurations of
;; installed packages.  Don't delete this line.  If you don't want it,
;; just comment it out by adding a semicolon to the start of the line.
;; You may delete these explanatory comments.
(package-initialize)

(setq-default auto-save-default nil)
(setq-default make-backup-files nil)
(setq-default create-lockfiles nil)


(require 'vc)

(autoload `mwheel-install "mwheel" "Enable mouse wheel support.")
(mwheel-install)
(global-set-key [button4] 'mwheel-scroll)
(global-set-key [button5] 'mwheel-scroll)

(setq auto-mode-alist ( cons ( cons "\\.h\\'" 'c++-mode) auto-mode-alist))
(setq auto-mode-alist ( cons ( cons "\\.c\\'" 'c++-mode) auto-mode-alist))
(setq auto-mode-alist ( cons ( cons "\\.dat\\'" 'c++-mode) auto-mode-alist))
(setq auto-mode-alist ( cons ( cons "\\.prt\\'" 'c++-mode) auto-mode-alist))
(setq auto-mode-alist ( cons ( cons "\\.plh\\'" 'c++-mode) auto-mode-alist))
(setq auto-mode-alist ( cons ( cons "\\.out\\'" 'c++-mode) auto-mode-alist))
(setq auto-mode-alist ( cons ( cons "\\.pg\\'" 'c++-mode) auto-mode-alist))
(setq auto-mode-alist ( cons ( cons "\\.p\\'" 'c++-mode) auto-mode-alist))

(put 'eval-expression 'disabled nil)
(put 'downcase-region 'disabled nil)
(put 'upcase-region 'disabled nil)

;;(set-background-color "GRAY90")
;;(global-font-lock-mode t)
;;
;;(set-default-font "-*-Lucida Console-normal-r-*-*-12-90-*-*-c-*-*-ansi-")
;;(setq process-coding-system-alist '(("cmdproxy" . (raw-text-dos . raw-text-dos))))
;;(setq-default c-site-default-style "stroustrup")
;;(setq-default c-basic-offset 4)
;;(c-mode)
;;(setq-default c-C++-conditional-key "\\b\\(for\\|if\\|do\\|else\\|while\\|switch\\|try\\|catch\\|TRY\\|CATCH\\)\\b[^_]")
;;(fundamental-mode)


;; Added by Denny 12/17/2015
;; add extra elpa packages
(setq package-archives '(("gnu" . "https://elpa.gnu.org/packages/")
                         ("marmalade" . "https://marmalade-repo.org/packages/")
                         ("melpa" . "https://melpa.org/packages/")))
