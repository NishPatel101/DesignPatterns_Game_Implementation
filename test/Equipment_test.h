#ifndef EQUIPMENT_TEST_H
#define EQUIPMENT_TEST_H

#include "gtest/gtest.h"

#include "../header/Sword.h"
#include "../header/Axe.h"
#include "../header/Flimsy.h"
#include "../header/Mighty.h"
#include "../header/Deadly.h"

TEST(EquipmentTest, Sword) {
        Equipment* test = new Sword;

        EXPECT_EQ(test->getDescription(), "Sword: the tried-and-true weapon!\nThis weapon has consistent, high damage output.");
        EXPECT_EQ(test->getDamage(), 5);
}

TEST(EquipmentTest, Axe) {
        Equipment* test = new Axe;
        int damage = test->getDamage();

        EXPECT_EQ(test->getDescription(), "Axe: a heavy but effective weapon for combat!\nThis weapon does lower base damage than the sword but can potentially land a critical blow.");
        EXPECT_TRUE(damage == 3 || damage == 7);
}

TEST(EquipmentTest, FlimsySword) {
        Equipment* s = new Sword;
        EquipmentDecorator* test = new Flimsy(s);

        EXPECT_EQ(test->getDescription(), "Flimsy Sword: the tried-and-true weapon!\nThis weapon has consistent, high damage output.\nThis weapon is flimsy, so it has a little more attack power.");
        EXPECT_EQ(test->getDamage(), 7);
}

TEST(EquipmentTest, FlimsyAxe) {
        Equipment* a = new Axe;
        EquipmentDecorator* test = new Flimsy(a);
        int damage = test->getDamage();

        EXPECT_EQ(test->getDescription(), "Flimsy Axe: a heavy but effective weapon for combat!\nThis weapon does lower base damage than the sword but can potentially land a critical blow.\nThis weapon is flimsy, so it has a little more attack power.");
        EXPECT_TRUE(damage == 5 || damage == 9);
}

TEST(EquipmentTest, MightySword) {
        Equipment* s = new Sword;
        EquipmentDecorator* test = new Mighty(s);

        EXPECT_EQ(test->getDescription(), "Mighty Sword: the tried-and-true weapon!\nThis weapon has consistent, high damage output.\nThis weapon is mighty, so it has more attack power.");
        EXPECT_EQ(test->getDamage(), 8);
}

TEST(EquipmentTest, MightyAxe) {
        Equipment* a = new Axe;
        EquipmentDecorator* test = new Mighty(a);
        int damage = test->getDamage();

        EXPECT_EQ(test->getDescription(), "Mighty Axe: a heavy but effective weapon for combat!\nThis weapon does lower base damage than the sword but can potentially land a critical blow.\nThis weapon is mighty, so it has more attack power.");
        EXPECT_TRUE(damage == 6 || damage == 10);
}

TEST(EquipmentTest, DeadlySword) {
        Equipment* s = new Sword;
        EquipmentDecorator* test = new Deadly(s);

        EXPECT_EQ(test->getDescription(), "Deadly Sword: the tried-and-true weapon!\nThis weapon has consistent, high damage output.\nThis weapon is deadly, so it has a lot more attack power.");
        EXPECT_EQ(test->getDamage(), 10);
}

TEST(EquipmentTest, DeadlyAxe) {
        Equipment* a = new Axe;
        EquipmentDecorator* test = new Deadly(a);
        int damage = test->getDamage();

        EXPECT_EQ(test->getDescription(), "Deadly Axe: a heavy but effective weapon for combat!\nThis weapon does lower base damage than the sword but can potentially land a critical blow.\nThis weapon is deadly, so it has a lot more attack power.");
        EXPECT_TRUE(damage == 8 || damage == 12);
}
#endif
