## TMPS LAb 1-3. Box facility
### FAF-193, A. Cornea 

### Description
Box facility offers a wide range of different types of boxes: prebuild "ready-to-go" boxes, intuitive box builder, custom boxes
and even custom composite boxes. Facility is accessed via **BoxFacility.h** singleton which acts as a facade.
User can request 3 different types: prebuild, custom and composite. Prebuild also consists of 3 sub-types: Shoe Box, Present Box and Food Box.

Each type/subtype of boxes is represented by different pattern. Most of the patterns are only technically implement and serve
little or no functionality

**BoxFacility** represents singleton and facade patterns  
**BoxFactory** represents factory pattern  
**BoxCompositor** allows to have a nested structure of boxes, hence representing composite patterns  
**Box** uses visitor pattern to traverse content of box, since container is homogeneous and requires special visitor  
**BoxBuilder** represents builder pattern with single builder implementation  
