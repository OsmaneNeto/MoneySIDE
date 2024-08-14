// *************************************************************
// Copyright (c) 1991-2024 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCannyEdgeDetectorCommand.h
//  Leadtools.ImageProcessing.Core
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSUInteger, LTCannyEdgeDetectorCommandChannels) {
    LTCannyEdgeDetectorCommandChannelsMaster  = 0, //CANNY_MASTER_CHANNEL,
    LTCannyEdgeDetectorCommandChannelsRed     = 1, //CANNY_RED_CHANNEL,
    LTCannyEdgeDetectorCommandChannelsGreen   = 2, //CANNY_GREEN_CHANNEL,
    LTCannyEdgeDetectorCommandChannelsBlue    = 4, //CANNY_BLUE_CHANNEL,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCannyEdgeDetectorCommand : LTRasterCommand

@property (nonatomic, assign) NSInteger radius;
@property (nonatomic, assign) NSInteger lowThreshold;
@property (nonatomic, assign) NSInteger highThreshold;
@property (nonatomic, assign) LTCannyEdgeDetectorCommandChannels channels;

@end

NS_ASSUME_NONNULL_END
