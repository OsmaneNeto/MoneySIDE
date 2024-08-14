// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTInvertedTextCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterRegion.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

#import <Leadtools.ImageProcessing.Core/LTEnums.h>

typedef NS_ENUM(NSUInteger, LTInvertedTextCommandFlags) {
    LTInvertedTextCommandFlagsNone           = 0x0000,
    LTInvertedTextCommandFlagsUseDpi         = 0x00000001,
    LTInvertedTextCommandFlagsSingleRegion   = 0x00000002,
    LTInvertedTextCommandFlagsLeadRegion     = 0x00000004,
    LTInvertedTextCommandFlagsCallBackRegion = 0x00000008,
    LTInvertedTextCommandFlagsImageUnchanged = 0x00000010,
    LTInvertedTextCommandFlagsUseDiagonals   = 0x00001000
};

NS_ASSUME_NONNULL_BEGIN

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTInvertedTextCommandEventArgs : NSObject

@property (nonatomic, strong, readonly, nullable) LTRasterRegion *region;

@property (nonatomic, assign, readonly)           LeadRect boundingRectangle;

@property (nonatomic, assign, readonly)           NSInteger whiteCount;
@property (nonatomic, assign, readonly)           NSInteger blackCount;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef void (^LTInvertedTextCommandStatus)(LTRasterImage *image, LTInvertedTextCommandEventArgs *args, LTRemoveStatus *status);

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTInvertedTextCommand : LTRasterCommand

@property (nonatomic, assign)                     LTInvertedTextCommandFlags flags;

@property (nonatomic, assign)                     NSInteger minimumInvertedWidth;
@property (nonatomic, assign)                     NSInteger minimumInvertedHeight;
@property (nonatomic, assign)                     NSInteger minimumBlackPercent;
@property (nonatomic, assign)                     NSInteger maximumBlackPercent;

@property (nonatomic, strong, readonly, nullable) LTRasterRegion *region;
@property (nonatomic, strong, readonly, nullable) LTRasterImage *imageRegion;

- (instancetype)initWithFlags:(LTInvertedTextCommandFlags)flags minimumInvertWidth:(NSInteger)minimumInvertWidth minimumInvertHeight:(NSInteger)minimumInvertHeight minimumBlackPercent:(NSInteger)minimumBlackPercent maximumBlackPercent:(NSInteger)maximumBlackPercent NS_DESIGNATED_INITIALIZER;

- (BOOL)run:(LTRasterImage *)image progress:(nullable LTRasterCommandProgress)progressHandler status:(nullable LTInvertedTextCommandStatus)invertedTextStatus error:(NSError **)error;

@end



@protocol LTInvertedTextCommandDelegate;

@interface LTInvertedTextCommand (Deprecated)

@property (nonatomic, weak, nullable) id<LTInvertedTextCommandDelegate> delegate LT_DEPRECATED_USENEW(19_0, "");

@end

NS_ASSUME_NONNULL_END
