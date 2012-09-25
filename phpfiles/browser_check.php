<?php
	require_once("browser.php");
    
    $browser = new Browser();
    
    const UNKNOWN = 0;
	const DEFAULTB = 1;
	const FIREFOX = 2;
	const CHROME = 3;
	const SAFARI = 4;
	const OPERA = 5;
	const IE = 6;
	const IPHONE = 7;
	const IPAD = 8;
    const ANDROID = 9;
	
	$bcode = UNKNOWN;
    $bver = 0;
	
	if(!$browser->isMobile()){
		switch($browser->getBrowser()){
			case (Browser::BROWSER_FIREFOX):
				$bcode = FIREFOX;
				break;
			case (Browser::BROWSER_CHROME):
				$bcode = CHROME;
				break;
			case (Browser::BROWSER_SAFARI):
				$bcode = SAFARI;
				break;
			case (Browser::BROWSER_OPERA):
				$bcode = OPERA;
				break;
			case (Browser::BROWSER_IE):
				$bcode = IE;
				break;
			case (Browser::BROWSER_IPHONE):
			case (Browser::BROWSER_IPOD):
				$bcode = IPHONE;
				break;
			case (Browser::BROWSER_IPAD):
				$bcode = IPAD;
				break;
            case (Browser::BROWSER_UNKNOWN):
                $bcode = UNKNOWN;
                break;
			default:
				$bcode = DEFAULTB;
				break;
		}
	} else {
		switch($browser->getBrowser()){
			case (Browser::BROWSER_IPHONE):
				$bcode = IPHONE;
				break;
			case (Browser::BROWSER_IPAD):
				$bcode = IPAD;
				break;
            case (Browser::BROWSER_ANDROID):
                $bcode = ANDROID;
                break;
            case (Browser::BROWSER_UNKNOWN):
                $bcode = UNKNOWN;
                break;
			default:
				$bcode = DEFAULTB;
				break;
		}
    }
    $bver = $browser->getVersion();
	
	$text = $browser->getBrowser()." ".$browser->getVersion()." ".$browser->getPlatform();
?>