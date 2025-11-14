extends Area2D
signal picked_up

var textures = {
	"cherry": "res://assets/sprites/cherry.png",
	"gem": "res://assets/sprites/gem.png"
}

#Sets texture and position of items
func init(type, _position):
	$Sprite2D.texture = load(textures[type])
	position = _position

#function to pick up items
func _on_item_body_entered(_body):
	picked_up.emit()
	queue_free()
