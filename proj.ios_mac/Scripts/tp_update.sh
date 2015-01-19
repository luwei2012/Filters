#!/bin/sh

#  PackTextures.sh
#  TestCoCo
#
#  Created by jiangrenxiang on 14-3-15.
#

#! /bin/sh



TP=/usr/local/bin/TexturePacker    #应用TexturePacker应用的路径
resourceRoot="../Resources"
#TP=~/Programming/TexturePacker/development/main-gui-build/source/app/TexturePacker.app/Contents/MacOS/TexturePacker

# 判断TexturePacker路径是否存在
if [ ! -L "$TP" ]; then
exit 0
fi


if [ "${ACTION}" = "clean" ]; then

echo "cleaning..."

rm -rf ../Resources/ipad/*.plist
rm -rf ../Resources/ipadhd/*.plist
rm -rf ../Resources/iphone/*.plist
rm -rf ../Resources/ipad/*.pvr
rm -rf ../Resources/ipadhd/*.pvr
rm -rf ../Resources/iphone/*.pvr

#find ../Resources -name gamescene_all_* | xargs rm


#elif [ "${ACTION}" = "install" ]; then
else

echo "building..."

#exit 0

#---------------tips_01.png RGBA4444-----------------------
${TP} ../Assets/BackGround/tips_01.png \
--format cocos2d \
--data ../Resources/SD/tips_01_{n}.plist \
--sheet ../Resources/SD/tips_01_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGB565 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack

#---------------tips_02.png RGBA4444-----------------------
${TP} ../Assets/BackGround/tips_02.png \
--format cocos2d \
--data ../Resources/SD/tips_02_{n}.plist \
--sheet ../Resources/SD/tips_02_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGB565 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack

#---------------tips_03.png RGBA4444-----------------------
${TP} ../Assets/BackGround/tips_03.png \
--format cocos2d \
--data ../Resources/SD/tips_03_{n}.plist \
--sheet ../Resources/SD/tips_03_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGB565 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack

#---------------tips_lomo_dark.png RGBA4444-----------------------
${TP} ../Assets/BackGround/tips_lomo_dark.png \
--format cocos2d \
--data ../Resources/SD/tips_lomo_dark_{n}.plist \
--sheet ../Resources/SD/tips_lomo_dark_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGBA8888 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack

##---------------bg_start.png RGBA4444-----------------------
#${TP} ../Assets/BackGround/bg_start.png \
#--format cocos2d \
#--data ../Resources/SD/bg_start_{n}.plist \
#--sheet ../Resources/SD/bg_start_{n}.pvr.ccz \
#--max-width "2048" \
#--max-height "2048" \
#--size-constraints NPOT \
#--opt RGB565 \
#--dither-fs \
#--shape-padding 0 \
#--border-padding 0 \
#--padding 0 \
#--texture-format pvr2ccz \
#--multipack

#---------------start_bg.png RGBA4444-----------------------
${TP} ../Assets/BackGround/start_bg.png \
--format cocos2d \
--data ../Resources/SD/start_bg_{n}.plist \
--sheet ../Resources/SD/start_bg_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGB565 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack


#---------------StartScene RGBA4444----------------------- 场景：1 ../Assets/StartScene/*.jpg
${TP} ../Assets/StartScene/*.png \
--format cocos2d \
--data ../Resources/{v}/startscene_all_{n}.plist \
--sheet ../Resources/{v}/startscene_all_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs-alpha  \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout


#---------------StartSceneSD RGBA4444-----------------------
${TP} ../Assets/StartSceneSD/*.png \
--format cocos2d \
--data ../Resources/SD/StartSceneSD_{n}.plist \
--sheet ../Resources/SD/StartSceneSD_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack


#---------------ShareSD RGBA4444-----------------------
${TP} ../Assets/ShareSD/*.png \
--format cocos2d \
--data ../Resources/SD/ShareSD_{n}.plist \
--sheet ../Resources/SD/ShareSD_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack


#---------------Number RGBA8888----------------------- ShareImage
${TP} ../Assets/Number/*.png \
--format cocos2d \
--data ../Resources/{v}/Number_{n}.plist \
--sheet ../Resources/{v}/Number_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA8888 \
--dither-fs-alpha  \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------ShareImage RGBA4444----------------------- ShareImage
${TP} ../Assets/ShareImage/*.png \
--format cocos2d \
--data ../Resources/{v}/share_image_all_{n}.plist \
--sheet ../Resources/{v}/share_image_all_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA8888 \
--dither-fs-alpha  \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

##---------------StartScene RGB565----------------------- 场景：2
#${TP} ../Assets/Map/*.png \
#--format cocos2d \
#--data ../Resources/SD/map_{n}.plist \
#--sheet ../Resources/SD/map_{n}.pvr.ccz \
#--max-width "2048" \
#--max-height "2048" \
#--size-constraints NPOT \
#--opt RGB565 \
#--dither-fs \
#--shape-padding 0 \
#--border-padding 0 \
#--padding 0 \
#--texture-format pvr2ccz \
#--multipack

#---------------StartScene RGB565----------------------- 场景：2
${TP} ../Assets/Coastline/*.png \
--format cocos2d \
--data ../Resources/SD/coastline_{n}.plist \
--sheet ../Resources/SD/coastline_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack


#---------------skillMain RGBA4444----------------------- 场景：2
${TP} ../Assets/skillMain/*.png \
--format cocos2d \
--data ../Resources/{v}/skillMain_{n}.plist \
--sheet ../Resources/{v}/skillMain_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs-alpha  \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------主动技能图片 RGBA4444----------------------- 场景：2
${TP} ../Assets/ActiveAbility/*.png \
--format cocos2d \
--data ../Resources/{v}/ActiveAbility_{n}.plist \
--sheet ../Resources/{v}/ActiveAbility_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs-alpha  \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout


#---------------GameSceneSD RGBA4444-----------------------
#${TP} ../Assets/GameSceneSD/*.png \
#--format cocos2d \
#--data ../Resources/SD/GameSceneSD_{n}.plist \
#--sheet ../Resources/SD/GameSceneSD_{n}.pvr.ccz \
#--max-width "2048" \
#--max-height "2048" \
#--size-constraints NPOT \
#--opt RGBA4444 \
#--dither-fs \
#--shape-padding 0 \
#--border-padding 0 \
#--padding 0 \
#--texture-format pvr2ccz \
#--multipack

#---------------GameScene RGBA4444----------------------- 场景：2
${TP} ../Assets/GameScene/*.png \
--format cocos2d \
--data ../Resources/{v}/gamescene_all_{n}.plist \
--sheet ../Resources/{v}/gamescene_all_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs-alpha  \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------GameScene RGBA4444----------------------- 场景：2
${TP} ../Assets/GameSceneBatch/*.png \
--format cocos2d \
--data ../Resources/{v}/gamescene_batch_{n}.plist \
--sheet ../Resources/{v}/gamescene_batch_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs-alpha  \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------skills_all RGBA4444----------------------- 场景：2
${TP} ../Assets/Skills/*.png \
--format cocos2d \
--data ../Resources/{v}/skills_all_{n}.plist \
--sheet ../Resources/{v}/skills_all_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs-alpha  \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout



#---------------StartScene RGBA8888-----------------------飞机轮船气泡
${TP} ../Assets/Animation/*.png \
--format cocos2d \
--data ../Resources/{v}/Animation_{n}.plist \
--sheet ../Resources/{v}/Animation_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA8888 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------StartScene RGBA8888-----------------------气泡收集
${TP} ../Assets/CollectEffect/*.png \
--format cocos2d \
--data ../Resources/{v}/CollectEffect_{n}.plist \
--sheet ../Resources/{v}/CollectEffect_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA8888 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout



#---------------countrydata_left_bottom.png RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/countrydata_left_bottom.png \
--format cocos2d \
--data ../Resources/{v}/countrydata_left_bottom_{n}.plist \
--sheet ../Resources/{v}/countrydata_left_bottom_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout



#---------------share_Nine_bg.png RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/share_Nine_bg.png \
--format cocos2d \
--data ../Resources/{v}/share_Nine_bg_{n}.plist \
--sheet ../Resources/{v}/share_Nine_bg_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------skill_top_bg RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/skill_top_bg.png \
--format cocos2d \
--data ../Resources/{v}/skill_top_bg_{n}.plist \
--sheet ../Resources/{v}/skill_top_bg_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------skill_bottom_bg RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/skill_bottom_bg.png \
--format cocos2d \
--data ../Resources/{v}/skill_bottom_bg_{n}.plist \
--sheet ../Resources/{v}/skill_bottom_bg_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout


#---------------Haiti_cable RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/Haiti_cable.png \
../Assets/skill_Ninebg/plane.png \
../Assets/skill_Ninebg/close_port.png \
--format cocos2d \
--data ../Resources/{v}/Haiti_cable_{n}.plist \
--sheet ../Resources/{v}/Haiti_cable_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------skill_label RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/skill_label.png \
--format cocos2d \
--data ../Resources/{v}/skill_label_{n}.plist \
--sheet ../Resources/{v}/skill_label_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------bg_logo_normal_map.png RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/bg_logo_normal_map.png \
--format cocos2d \
--data ../Resources/{v}/bg_logo_normal_map_{n}.plist \
--sheet ../Resources/{v}/bg_logo_normal_map_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------bg_logo_normal_map.png RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/bg_logo.png \
--format cocos2d \
--data ../Resources/{v}/bg_logo_{n}.plist \
--sheet ../Resources/{v}/bg_logo_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------World_top_bg.png RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/World_top_bg.png \
--format cocos2d \
--data ../Resources/{v}/World_top_bg_{n}.plist \
--sheet ../Resources/{v}/World_top_bg_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------country_top_bg.png RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/country_top_bg.png \
--format cocos2d \
--data ../Resources/{v}/country_top_bg_{n}.plist \
--sheet ../Resources/{v}/country_top_bg_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

#---------------active_skill_cross.png RGBA4444-----------------------
${TP} ../Assets/skill_Ninebg/active_skill_cross_destroy.png \
--format cocos2d \
--data ../Resources/{v}/active_skill_cross_destroy_{n}.plist \
--sheet ../Resources/{v}/active_skill_cross_destroy_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout





#---------------Plate RGBA4444-----------------------地图板块
${TP} ../Assets/Plate/*.png \
--format cocos2d \
--data ../Resources/SD/Plate_{n}.plist \
--sheet ../Resources/SD/Plate_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack

#---------------PlateDeath RGBA4444-----------------------地图板块
${TP} ../Assets/Plate_Death/*.png \
--format cocos2d \
--data ../Resources/SD/Plate_Death_{n}.plist \
--sheet ../Resources/SD/Plate_Death_{n}.pvr.ccz \
--max-width "2048" \
--max-height "2048" \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--shape-padding 0 \
--border-padding 0 \
--padding 0 \
--texture-format pvr2ccz \
--multipack


#---------------GameResult RGBA4444-----------------------胜利失败界面
${TP} ../Assets/GameResult/*.png \
--format cocos2d \
--data ../Resources/{v}/GameResult_{n}.plist \
--sheet ../Resources/{v}/GameResult_{n}.pvr.ccz \
--size-constraints NPOT \
--opt RGBA4444 \
--dither-fs \
--texture-format pvr2ccz \
--multipack \
--variant 1:/HD/::allowfraction:4096:4096 \
--variant 0.5:/SD/::allowfraction:2048:2048 \
--force-identical-layout

fi
exit 0
