__main
	-- check for arg errors
		- check nb of arg
		- check map file
	
	-- parse map
		- put map into char**
			-- get window dimensions
		- check map for error
			-- is it rectangular ?
			-- is there 4 walls ?
			-- is there only allowed signs ?
			-- can I backtrack through it ?
		- get player position

	-- setup_game
		- parse map
		- mlx_init
			-- create window
			-- create image
			-- retrieve sprites

	-- mlx_loop
		- key_hooks
			-- moves
			-- destroy
		- draw map
			-- put_image_to_window
		- loop
