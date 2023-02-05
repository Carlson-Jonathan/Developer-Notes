
-- This is a comment

with Ada.Text_IO; use Ada.Text_IO; -- "with" is basically 'include' in C++

procedure helloworld is		-- The same as 'int main()'. Function name must match file name.
begin				-- Must specify beginning of function
   Put_Line ("Hello, World!");  -- cout / console.log / printf() / etc.
end helloworld;			-- Must specify end of function

-- Compile and run instructions:
   -- gnat compile helloWorld.adb (creates files)
   -- gnatbind helloWorld	  (function name only)
   -- gnatlink helloWorld	  (removes files and creates executable)
   -- ./helloWorld		  (runs generated file)
