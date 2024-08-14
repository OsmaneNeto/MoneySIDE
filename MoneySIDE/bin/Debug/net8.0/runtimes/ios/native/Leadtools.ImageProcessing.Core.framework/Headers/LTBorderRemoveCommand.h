// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTBorderRemoveCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterRegion.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTPrimitives.h>

#import <Leadtools.ImageProcessing.Core/LTEnums.h>

typedef NS_OPTIONS(NSUInteger, LTBorderRemoveCommandFlags) {
    LTBorderRemoveCommandFlagsNone            = 0x0000,
    LTBorderRemoveCommandFlagsSingleRegion    = 0x00000002,
    LTBorderRemoveCommandFlagsLeadRegion      = 0x00000004,
    LTBorderRemoveCommandFlagsCallBackRegion  = 0x00000008,
    LTBorderRemoveCommandFlagsImageUnchanged  = 0x00000010,
    LTBorderRemoveCommandFlagsUseVariance     = 0x00000800,
    LTBorderRemoveCommandFlagsAutoRemove      = 0x00001000
};

typedef NS_OPTIONS(NSUInteger, LTBorderRemoveBorderFlags) {
    LTBorderRemoveBorderFlagsNone   = 0x0000,
    LTBorderRemoveBorderFlagsLeft   = 0x0001,
    LTBorderRemoveBorderFlagsTop    = 0x0004,
    LTBorderRemoveBorderFlagsRight  = 0x0002,
    LTBorderRemoveBorderFlagsBottom = 0x0008,
    LTBorderRemoveBorderFlagsAll    = 0x0001 | 0x0004 | 0x0002 |0x0008
};

NS_ASSUME_NONNULL_BEGIN

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTBorderRemoveCommandEventArgs : NSObject

@property (nonatomic, strong, readonly) LTRasterRegion *region;

@property (nonatomic, assign, readonly) LTBorderRemoveBorderFlags border;

@property (nonatomic, assign, readonly) LeadRect boundingRectangle;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef void (^LTBorderRemoveCommandStatus)(LTRasterImage *image, LTBorderRemoveCommandEventArgs *args, LTRemoveStatus *status);

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTBorderRemoveCommand : LTRasterCommand

@property (nonatomic, assign)                     LTBorderRemoveCommandFlags flags;
@property (nonatomic, assign)                     LTBorderRemoveBorderFlags border;

@property (nonatomic, assign)                     NSInteger percent;
@property (nonatomic, assign)                     NSInteger whiteNoiseLength;
@property (nonatomic, assign)                     NSInteger variance;

@property (nonatomic, strong, readonly, nullable) LTRasterRegion *region;
@property (nonatomic, strong, readonly, nullable) LTRasterImage *imageRegion;

- (instancetype)initWithFlags:(LTBorderRemoveCommandFlags)flags border:(LTBorderRemoveBorderFlags)border percent:(NSInteger)percent whiteNoiseLength:(NSInteger)whiteNoiseLength variance:(NSInteger)variance NS_DESIGNATED_INITIALIZER;

- (BOOL)run:(LTRasterImage *)image progress:(nullable LTRasterCommandProgress)progressHandler status:(nullable LTBorderRemoveCommandStatus)borderRemoveStatus error:(NSError **)error;

@end



@protocol LTBorderRemoveCommandDelegate;

@interface LTBorderRemoveCommand (Deprecated)

@property (nonatomic, weak, nullable) id<LTBorderRemoveCommandDelegate> delegate LT_DEPRECATED_USENEW(19_0, "run:progress:status:error:");

@end

NS_ASSUME_NONNULL_END
