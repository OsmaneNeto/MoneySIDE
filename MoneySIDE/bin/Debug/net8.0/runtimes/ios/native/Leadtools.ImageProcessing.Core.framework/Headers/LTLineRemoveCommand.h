// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTLineRemoveCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterRegion.h>
#import <Leadtools/LTRasterImage.h>

#import <Leadtools.ImageProcessing.Core/LTEnums.h>

typedef NS_OPTIONS(NSUInteger, LTLineRemoveCommandType) {
    LTLineRemoveCommandTypeHorizontal = 0x0001,
    LTLineRemoveCommandTypeVertical   = 0x0002,
};

typedef NS_OPTIONS(NSUInteger, LTLineRemoveCommandFlags) {
    LTLineRemoveCommandFlagsNone           = 0x0000,
    LTLineRemoveCommandFlagsUseDpi         = 0x00000001,
    LTLineRemoveCommandFlagsSingleRegion   = 0x00000002,
    LTLineRemoveCommandFlagsLeadRegion     = 0x00000004,
    LTLineRemoveCommandFlagsCallBackRegion = 0x00000008,
    LTLineRemoveCommandFlagsImageUnchanged = 0x00000010,
    LTLineRemoveCommandFlagsRemoveEntire   = 0x00000200,
    LTLineRemoveCommandFlagsUseGap         = 0x00000400,
    LTLineRemoveCommandFlagsUseVariance    = 0x00000800
};

NS_ASSUME_NONNULL_BEGIN

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLineRemoveCommandEventArgs : NSObject

@property (nonatomic, strong, readonly, nullable) LTRasterRegion *region;

@property (nonatomic, assign, readonly)           NSInteger startRow;
@property (nonatomic, assign, readonly)           NSInteger startColumn;
@property (nonatomic, assign, readonly)           NSInteger length;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef void (^LTLineRemoveCommandStatus)(LTRasterImage *image, LTLineRemoveCommandEventArgs *args, LTRemoveStatus *status);

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLineRemoveCommand : LTRasterCommand

@property (nonatomic, assign)                     LTLineRemoveCommandFlags flags;
@property (nonatomic, assign)                     LTLineRemoveCommandType type;

@property (nonatomic, assign)                     NSInteger minimumLineLength;
@property (nonatomic, assign)                     NSInteger maximumLineWidth;
@property (nonatomic, assign)                     NSInteger wall;
@property (nonatomic, assign)                     NSInteger maximumWallPercent;
@property (nonatomic, assign)                     NSInteger gapLength;
@property (nonatomic, assign)                     NSInteger variance;

@property (nonatomic, strong, readonly, nullable) LTRasterRegion *region;
@property (nonatomic, strong, readonly, nullable) LTRasterImage *imageRegion;

- (instancetype)initWithFlags:(LTLineRemoveCommandFlags)flags minimumLineLength:(NSInteger)minimumLineLength maximumLineWidth:(NSInteger)maximumLineWidth wall:(NSInteger)wall maximumWallPercent:(NSInteger)maximumWallPercent gapLength:(NSInteger)gapLength variance:(NSInteger)variance type:(LTLineRemoveCommandType)type NS_DESIGNATED_INITIALIZER;

- (BOOL)run:(LTRasterImage *)image progress:(nullable LTRasterCommandProgress)progressHandler status:(nullable LTLineRemoveCommandStatus)lineRemoveStatus error:(NSError **)error;

@end



@protocol LTLineRemoveCommandDelegate;

@interface LTLineRemoveCommand (Deprecated)

@property (nonatomic, weak, nullable) id<LTLineRemoveCommandDelegate> delegate LT_DEPRECATED_USENEW(19_0, "run:progress:status:error:");

@end

NS_ASSUME_NONNULL_END
