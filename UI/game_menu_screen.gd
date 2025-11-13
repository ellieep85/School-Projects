extends CanvasLayer


func _on_start_game_button_pressed() -> void:
	get_tree().change_scene_to_file("res://scenes/main/main.tscn")



func _on_exit_game_button_pressed() -> void:
	get_tree().quit()
