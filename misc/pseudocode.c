__main
	-- check for arg errors
		- check nb of arg
		- check map file
	
	-- parse map
		- get window dimensions
		- put map into char**
		- check map for error
			-- is there minimum 3 rows and 3 columns ?
			-- is it rectangular ?
			-- is there 4 walls ?
			-- is there only allowed signs ?
			-- at least one player and one exit ?
			-- can I backtrack through it ?
		- get player position
		- count collectibles

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
