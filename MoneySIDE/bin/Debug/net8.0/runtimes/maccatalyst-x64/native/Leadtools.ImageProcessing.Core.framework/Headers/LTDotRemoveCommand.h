// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTDotRemoveCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterRegion.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

#import <Leadtools.ImageProcessing.Core/LTEnums.h>

typedef NS_OPTIONS(NSUInteger, LTDotRemoveCommandFlags) {
    LTDotRemoveCommandFlagsNone           = 0x0000,
    LTDotRemoveCommandFlagsUseDpi         = 0x00000001,
    LTDotRemoveCommandFlagsSingleRegion   = 0x00000002,
    LTDotRemoveCommandFlagsLeadRegion     = 0x00000004,
    LTDotRemoveCommandFlagsCallBackRegion = 0x00000008,
    LTDotRemoveCommandFlagsImageUnchanged = 0x00000010,
    LTDotRemoveCommandFlagsUseSize        = 0x00000020,
    LTDotRemoveCommandFlagsUseDiagonals   = 0x00001000
};

NS_ASSUME_NONNULL_BEGIN

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDotRemoveCommandEventArgs : NSObject

@property (nonatomic, strong, readonly, nullable) LTRasterRegion *region;

@property (nonatomic, assign, readonly)           LeadRect boundingRectangle;

@property (nonatomic, assign, readonly)           NSInteger whiteCount;
@property (nonatomic, assign, readonly)           NSInteger blackCount;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef void (^LTDotRemoveCommandStatus)(LTRasterImage *image, LTDotRemoveCommandEventArgs *args, LTRemoveStatus *status);

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTDotRemoveCommand : LTRasterCommand

@property (nonatomic, assign)                     LTDotRemoveCommandFlags flags;

@property (nonatomic, assign)                     NSInteger minimumDotWidth;
@property (nonatomic, assign)                     NSInteger minimumDotHeight;
@property (nonatomic, assign)                     NSInteger maximumDotWidth;
@property (nonatomic, assign)                     NSInteger maximumDotHeight;

@property (nonatomic, strong, readonly, nullable) LTRasterRegion *region;
@property (nonatomic, strong, readonly, nullable) LTRasterImage *imageRegion;


- (instancetype)initWithFlags:(LTDotRemoveCommandFlags)flags minimumDotWidth:(NSInteger)minimumDotWidth minimumDotHeight:(NSInteger)minimumDotHeight maximumDotWidth:(NSInteger)maximumDotWidth maximumDotHeight:(NSInteger)maximumDotHeight NS_DESIGNATED_INITIALIZER;

- (BOOL)run:(LTRasterImage *)image progress:(nullable LTRasterCommandProgress)progressHandler status:(nullable LTDotRemoveCommandStatus)dotRemoveStatus error:(NSError **)error;

@end



@protocol LTDotRemoveCommandDelegate;

@interface LTDotRemoveCommand (Deprecated)

@property (nonatomic, weak, nullable) id<LTDotRemoveCommandDelegate> delegate LT_DEPRECATED_USENEW(19_0, "run:progress:status:error:");

@end

NS_ASSUME_NONNULL_END
