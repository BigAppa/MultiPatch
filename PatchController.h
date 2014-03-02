#import <Cocoa/Cocoa.h>

typedef enum PatchTypes{
	UNKNOWNPAT, UPSPAT, XDELTAPAT, IPSPAT, PPFPAT, BSDIFFPAT, BPSPAT, BPSDELTA
} PatchFormat;

@interface PatchController : NSObject{
    IBOutlet id txtPatchPath;
    IBOutlet id txtRomPath;
	IBOutlet id txtOutputPath;
	IBOutlet id lblPatchFormat;
    IBOutlet id wndPatcher;
    IBOutlet NSWindow *wndCreator;
	IBOutlet id pnlPatching;
	IBOutlet id	barProgress;
	IBOutlet id btnApply;
	IBOutlet NSTextField *lblStatus;
	PatchFormat currentFormat;
	NSString* romFormat;
}

- (IBAction)btnApply:(id)sender;
- (IBAction)btnBrowse:(id)sender;
- (IBAction)btnSelectPatch:(id)sender;
- (IBAction)btnSelectOutput:(id)sender;
- (void)openPanelDidEnd:(NSOpenPanel*)panel returnCode:(int)returnCode contextInfo:(void*)contextInfo; //Called automatically
- (void)selPatchPanelEnd:(NSOpenPanel*)panel returnCode:(int)returnCode contextInfo:(void*)contextInfo;
- (void)selOutputPanelEnd:(NSSavePanel*)panel returnCode:(int)returnCode contextInfo:(void*)contextInfo;
+ (PatchFormat)detectPatchFormat:(NSString*)patchPath;
- (NSString*)ApplyPatch:(NSString*)patchPath :(NSString*)sourceFile :(NSString*)destFile;
- (IBAction)btnCreatePatch:(id)sender;
@end
