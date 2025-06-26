/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

extern bool is_drag_scroll;
uint16_t overall_scroll_distance = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT( DRAG_SCROLL, LCA(KC_TAB), KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (is_drag_scroll && ((keycode == KC_BTN1 || keycode == KC_BTN2 || keycode == KC_BTN3) ||
			       (keycode == DRAG_SCROLL && !record->event.pressed &&
				overall_scroll_distance > REARMAN_PLOOPY_RELEASE_ADHOC_DISTANCE))) {
		is_drag_scroll = false;
		pointing_device_set_cpi(dpi_array[keyboard_config.dpi_config]);
		return false;
	}
	return true;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
	if(is_drag_scroll) {
		overall_scroll_distance += abs(mouse_report.v) + abs(mouse_report.h);
	} else {
		overall_scroll_distance = 0;
	}
	return mouse_report;
}
